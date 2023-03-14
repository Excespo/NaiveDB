#include "query/execution/executor/group_by_executor.h"

#include "storage/tuple/tuple.h"

namespace naivedb::query {
void GroupByExecutor::init() {
    // TODO(Project-1): Implement this method
    child_executor_ = child_at(0);
    child_executor_->init();
    const catalog::Schema *schema = plan_->child()->output_schema();
    std::vector<storage::Tuple> child_tuple;

    while (!(child_tuple = child_executor_->next()).empty()) {
        type::Value group_value = child_tuple[0].value_at(schema, plan_->column_id());
        auto iter = buckets_.find(group_value);
        if (iter == buckets_.end()) {
            buckets_.emplace(group_value, make_vector(std::move(child_tuple[0])));
        } else {
            iter->second.push_back(std::move(child_tuple[0]));
        }
    }

    buckets_iter_ = buckets_.begin();
}

std::vector<storage::Tuple> GroupByExecutor::next() {
    // TODO(Project-1): Implement this method
    if (buckets_iter_ != buckets_.end()) {
        auto &[group_by_value, tuples] = *buckets_iter_++;
        return std::move(tuples);
    }
    return {};
}
}  // namespace naivedb::query