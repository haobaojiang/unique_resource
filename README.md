## unique_resource
- this is a simple RAII wrapper for any resource (file descriptors, sockets,handles)
## example 
```cpp
#include "unique_resource.h"
#include <iostream>


using unique_file = unique_resource<FILE*, fclose>;

int main() {

  // Create a unique resource for a file descriptor
  unique_file f(fopen("filename.txt", "w"));


  // Use the file descriptor


  // Write some text to the file
  fprintf(f.get(), "Some text");

  // No need to manually close the file descriptor
  // It will be automatically closed when fd_resource goes out of scope

  return 0;
}

```
