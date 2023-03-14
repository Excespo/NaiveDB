#include "query/execution/executor/hash_join_executor.h"

#include "common/utils.h"
#include "storage/tuple/tuple.h"
#include "type/value.h"

namespace naivedb::query {
void HashJoinExecutor::init() {
    // TODO(Project-1): Implement this method
    left_child_executor_ = child_at(0);
    left_child_executor_->init();
    right_child_executor_ = child_at(1);
    right_child_executor_->init();
    left_schema_ = plan_->left_plan()->output_schema();
    right_schema_ = plan_->right_plan()->output_schema();

    // right_ = right_child_executor_->next();

    const Expr *left_expr = plan_->left_key_expr();
    std::vector<storage::Tuple> left;
    while (!(left = left_child_executor_->next()).empty()) {
        type::Value value = left_expr->evaluate(left[0], left_schema_);
        int32_t hash = static_cast<int32_t>(std::hash<type::Value>()(value));
        fmt::print("prepare hash on value: {}, get {}, ", value, hash);
        auto item = hash_table_.emplace(type::Value(hash),
                                        std::move(left[0]));  // use std::move for constructor concerning tuple !!!
        // hash_table_.emplace(type::Value(hash), std::move(left[0]));
        fmt::print("emplace done? {}, key: {}, tuple: {}\n",
                   item.second,
                   item.first->first,
                   fmt::join(item.first->second.values(left_schema_), ", "));
    }
    // hash_iter_ = hash_table_.begin();
}

std::vector<storage::Tuple> HashJoinExecutor::next() {
    // TODO(Project-1): Implement this method
    while (true) {
        right_ = right_child_executor_->next();
        if (right_.empty())
            return {};

        type::Value val_ = plan_->right_key_expr()->evaluate(right_[0], right_schema_);
        int32_t hash = static_cast<int32_t>(std::hash<type::Value>()(val_));
        auto iter = hash_table_.find(type::Value(hash));
        fmt::print("find? {}, at left tuple {} with right tuple {}\n",
                   iter->first,
                   fmt::join(iter->second.values(left_schema_), ", "),
                   fmt::join(right_[0].values(right_schema_), ", "));
        if (iter == hash_table_.end()) {
            continue;
        } else {
            // storage::Tuple left = std::move(iter->second);
            std::vector<type::Value> values = iter->second.values(left_schema_),
                                     right_values = right_[0].values(right_schema_);
            values.insert(values.end(), right_values.begin(), right_values.end());
            return make_vector(std::move(storage::Tuple(std::move(values))));
        }
    }
    return {};
}
}  // namespace naivedb::query