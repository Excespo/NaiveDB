#include "query/execution/executor/insert_executor.h"

#include "catalog/catalog.h"
#include "catalog/table_info.h"
#include "storage/table/table_heap.h"
#include "storage/tuple/tuple.h"

namespace naivedb::query {
void InsertExecutor::init() {
    // TODO(Project-1): Implement this method
    auto table_info = context().catalog()->get_table_info(plan_->table_id());
    table_heap_ = std::make_unique<storage::TableHeap>(context().buffer_manager(), table_info.root_page_id());
}

std::vector<storage::Tuple> InsertExecutor::next() {
    // TODO(Project-1): Implement this method
    std::vector<std::vector<type::Value>> raw_values_ = plan_->raw_values();
    for (auto raw_value_ : raw_values_) {
        storage::Tuple tuple_(raw_value_);
        table_heap_->insert_tuple(tuple_);
    }
    return {};
}
}  // namespace naivedb::query