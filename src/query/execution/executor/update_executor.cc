#include "query/execution/executor/update_executor.h"

#include "catalog/catalog.h"
#include "catalog/table_info.h"
#include "storage/table/table_heap.h"
#include "storage/tuple/tuple.h"
#include "type/value.h"

namespace naivedb::query {
void UpdateExecutor::init() {
    // TODO(Project-1): Implement this method
    auto table_info = context().catalog()->get_table_info(plan_->table_id());
    table_heap_ = std::make_unique<storage::TableHeap>(context().buffer_manager(), table_info.root_page_id());
    table_iter_ = table_heap_->begin();
    table_schema_ = table_info.schema();
}

std::vector<storage::Tuple> UpdateExecutor::next() {
    // TODO(Project-1): Implement this method
    const Expr *predicate = plan_->predicate();

    while (table_iter_ != table_heap_->end()) {
        tuple_id_t tuple_id = table_iter_.tuple_id();
        auto tuple = *table_iter_++;
        bool satisfied = (predicate == nullptr) ? true : (predicate->evaluate(tuple, table_schema_)).as<bool>();

        if (satisfied) {
            for (auto [col_id, new_val] : plan_->update_columns()) {
                tuple.set_value_at(table_schema_, col_id, new_val);
            }
            table_heap_->update_tuple(tuple_id, tuple);
        }
    }

    return {};
}
}  // namespace naivedb::query