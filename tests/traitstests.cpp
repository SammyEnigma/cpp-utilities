#include "../misc/traits.h"

#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;
using namespace Traits;

struct SomeStruct {
    string foo;
    int bar;
};

static_assert(!Bool<false>::value, "Bool<false>");
static_assert(Bool<true>::value, "Bool<true>");
static_assert(!Not<Bool<true>>::value, "Not");
static_assert(!Any<Bool<false>, Bool<false>>::value, "Any: negative case");
static_assert(Any<Bool<true>, Bool<false>>::value, "Any: positive case");
static_assert(!All<Bool<true>, Bool<false>>::value, "All: negative case");
static_assert(All<Bool<true>, Bool<true>>::value, "All: positive case");

static_assert(!IsSpecializationOf<string, basic_stringbuf>::value, "IsSpecializationOf: negative case");
static_assert(IsSpecializationOf<string, basic_string>::value, "IsSpecializationOf: positive case");

static_assert(!IsIteratable<int>::value, "IsIterator: negative case");
static_assert(!IsIteratable<SomeStruct>::value, "IsIterator: negative case");
static_assert(IsIteratable<string>::value, "IsIterator: positive case");
static_assert(IsIteratable<vector<int>>::value, "IsIterator: positive case");
static_assert(IsIteratable<list<string>>::value, "IsIterator: positive case");
static_assert(IsIteratable<map<string, string>>::value, "IsIterator: positive case");
static_assert(IsIteratable<initializer_list<double>>::value, "IsIterator: positive case");
