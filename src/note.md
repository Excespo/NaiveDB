WHAT IS DIR DOING?

# common

`types.h` Define here all basic types

`constants.h` Define here constants

`macros.h` Define here macros, including `DISALLOW_COPY_AND_MOVE` ...

`utils.h` Define here some fold expressions, including `move_vector` ...

`format.h` Define a `fmt` namespace (do what? formatter?)

`exception.h` Define here exceptions

# type

`type_id.h` Define `Boolean`, `Int`, ... classes for comparison

`type.h` Define a `naivedb::type` namespace, and similar `Type` class to those in `type_id.h` and formatter

`value.h` Define a `Value` class and formatter, and a `hash` in namespace std (is it admitted? for what?)

`value.cc` Implement operators for class `Value`, and `hash`

# io

It's namespace `naivedb::io`

##`disk_manager.h`
Designation: A hierarchy of MasterPage - HeaderPage - DataPage(of size 4K)

MasterPage(16bit int) indicates the number of DataPage allocated in HeaderPage(4K / 2 = 2K HeaderPages)

HeaderPage(bitmap) indicates the allocation of DataPage(4K * 8 = 32K DataPages)

It published the following methods:
 - `explicit DiskManager(std::string_view file_name);` a ctor with explicit arg of type `string_view`
 - `~DiskManager();` a dtor
 - `page_id_t alloc_page();` to allocate a new page
 - `void free_page(page_id_t page_id);` to deallocate a page
 - `void read_page(page_id_t page_id, char *page_data);` to read data from a page
 - `void write_page(page_id_t page_id, const char *page_data)` to write data on a page
 - `bool page_allocated(page_id_t page_id);` to check if the page is allocated

##`disk_manager.cc`
Implement `disk_manager.cc`


# catalog

##`column.h`
It's namespace `naivedb::catalog`, used to provide (mata)information of the column's header, including name and type

Define here class `Column`, it published the following methods:
 - `explicit Column(const std::pair<std::string_view, type::Type> &pair);` a ctor with arg column name and type
 - ... 

##`schema.h`
It's namespace `naivedb::catalog`, construct with a vector of type `Column`, 
Define here `naivedb::catalog::Schema`, used to provide (meta)information of the schema's header, including all the columns and the offsets(depending on the type of column, which corresponds to different size)

##`table_info.h`
including table id, table name, schema, root page id

##`catalog.h`
Define here `naivedb::catalog::Catalog`, used to store the information of a series of tables, including:
 - a buffer manager
 - an unordered map from table name to table index
 - a vector of the `InnerTableInfo` struct, with member name, schema, root page id
 - free slots(it's what?)

# buffer
It's namespace `naivedb::buffer`

## 

# query/physical_plan
It's namespace `naivedb::query`

## `physical_plan.h`
The class `PhysicalPlan` represents all possible types of physical plan nodes (actually a node of a  tree by the volcano model)
Note that this file doesn't include `catalog/catalog.h` but can use `catalog::Schema`, by declaring first the namespace structure (Why it works?)

`PhysicalPlan(const catalog::schema *output_schema srd::vector<std::unique_ptr<const PhysicalPlan>> &&children);` take into the schema for output of the plan node and children of this plan node as ctor args.

`~PhysicalPlan() = default;` dtor

`const catalog::schema *output_schema();` get the schema for the output of the physical plan node

`const PhysicalPlan *child_at(size_t child_id);` get the child of the plan node at given index

`const std::vector<std::unique_ptr<const PhysicalPlan>> &children();` get all the children of the plan node

`void accept(PhysicalPlanVisitor);` accept the plan visitor(For what?)

## `physical_plan_visitor.h`
The class `PhysicalPlanVisitor` is the abstract class for physical plan visitors

`virtual void visit(const SOME_PHYSICAL_PLAN *) = 0;`
`SOME_PHYSICAL_PLAN` can be `PhysicalHashJoin`, `PhysicalInsert`, `PhysicalNestedLoopJoin`, `PhysicalProjection`, `PhysicalSeqScan`, `PhysicalFilter`, `PhysicalGroupBy`, `PhysicalAggregate`, `PhysicalUpdate`

## `physical_hash_join.h`
Construct with the schema for output, two sequential scan children plan(left and right), the expression for left and right keys

# query/expr


# query/execution




# query/execution/executor
