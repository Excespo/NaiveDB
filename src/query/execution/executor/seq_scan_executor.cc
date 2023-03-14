#include "query/execution/executor/seq_scan_executor.h"

#include "catalog/catalog.h"
#include "catalog/table_info.h"
#include "common/utils.h"
#include "storage/table/table_heap.h"
#include "storage/tuple/tuple.h"

namespace naivedb::query {
void SeqScanExecutor::init() {
    // TODO(Project-1): Implement this method
    auto table_info = context().catalog()->get_table_info(plan_->table_id());
    table_heap_ = std::make_unique<storage::TableHeap>(context().buffer_manager(), table_info.root_page_id());
    table_iter_ = table_heap_->begin();
}

std::vector<storage::Tuple> SeqScanExecutor::next() {
    // TODO(Project-1): Implement this method
    if (table_iter_ != table_heap_->end()) {
        auto tuple = *table_iter_++;
        return make_vector(std::move(tuple));
    }
    return {};
}
}  // namespace naivedb::query