#include "query/execution/executor/nested_loop_join_executor.h"

#include "storage/tuple/tuple.h"
#include "type/value.h"

namespace naivedb::query {
void NestedLoopJoinExecutor::init() {
    // TODO(Project-1): Implement this method
    left_plan_ = plan_->left_plan();
    right_plan_ = plan_->right_plan();
    left_child_executor = child_at(0);
    left_child_executor->init();
    right_child_executor = child_at(1);
    right_child_executor->init();
    left_ = left_child_executor->next();
}

std::vector<storage::Tuple> NestedLoopJoinExecutor::next() {
    // TODO(Project-1): Implement this method
    const Expr *join_predicate = plan_->predicate();
    std::vector<storage::Tuple> right_tuples;
    const catalog::Schema *left_schema = left_plan_->output_schema(), *right_schema = right_plan_->output_schema();

    // fmt::print("curr left is: {}\n", fmt::join(left_[0].values(left_schema), ", "));
    if (join_predicate == nullptr) {
        // fmt::print("Case without join predicate\n");
        while (true) {
            right_tuples = right_child_executor->next();
            if (right_tuples.empty()) {
                left_ = left_child_executor->next();
                if (left_.empty())
                    return {};
                right_child_executor->init();
                continue;
            }
            // fmt::print("curr left is: {}\n", fmt::join(left_[0].values(left_schema), ", "));
            // fmt::print("curr right is: {}\n", fmt::join(right_tuples[0].values(right_schema), ", "));
            break;
        }
        storage::Tuple tuple;
        std::vector<type::Value> values = left_[0].values(left_schema),
                                 right_values = right_tuples[0].values(right_schema);
        values.insert(values.end(), right_values.begin(), right_values.end());
        // storage::Tuple join_tuple(std::move(values));
        return make_vector(std::move(storage::Tuple(std::move(values))));
    } else {
        while (true) {
            right_tuples = right_child_executor->next();
            if (right_tuples.empty()) {
                left_ = left_child_executor->next();
                if (left_.empty())
                    return {};
                // fmt::print("curr left is: {}\n", fmt::join(left_[0].values(left_schema), ", "));
                right_child_executor->init();
                continue;
            }
            bool fit = join_predicate->evaluate_join(left_[0], right_tuples[0], left_schema, right_schema).as<bool>();
            // fmt::print("curr right is {}. fit? {}\n", fmt::join(right_tuples[0].values(right_schema), ", "), fit);
            if (fit)
                break;
        }
        storage::Tuple tuple;
        std::vector<type::Value> values = left_[0].values(left_schema),
                                 right_values = right_tuples[0].values(right_schema);
        const Expr *left_expr = join_predicate->child_at(0);
        type::Value join_value = left_expr->evaluate(left_[0], left_schema);
        // for (auto const &val: right_tuples[0].values(right_schema)) {
        //     // if (val == join_value) continue;
        //     values.emplace_back(val);
        // }
        values.insert(values.end(), right_values.begin(), right_values.end());
        // storage::Tuple join_tuple(std::move(values));
        // fmt::print("join on value: {}. result in {}, with {} attrs\n", join_value, fmt::join(values, ", "),
        // values.size());
        return make_vector(std::move(storage::Tuple(std::move(values))));
    }

    return {};
}
}  // namespace naivedb::query