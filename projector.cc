#include <forward_list>
#include <iostream>
#include <memory>

using namespace std;

struct Link {
    string link;
    string title;
    using link_ptr = unique_ptr<Link>;
};

/*
## Lynx
   add link
   remove it
   update it
   get
*/

/*
## quotium interface
    add quote, author
    delete
    update
    get
*/

/*
## apologia
add text, source
delete, update, get
*/

/*
## Sourcum
add file or link, with source
delete, update, get
*/

int main() {
    forward_list<Link::link_ptr> links;

    return 0;
}
