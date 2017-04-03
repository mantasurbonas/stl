# stl  
bare minimum STL classes for C++. Only binary mode supported.  

STL (STereoLithography) is a popular file format for 3D printers.  

https://en.wikipedia.org/wiki/STL_(file_format)  


## example  

```c++
Stl::Builder builder;

builder.makeTriangle(normal1, a, b, c);
builder.makeTriangle(normal2, a2, b2, c2);
builder.makeCube(x, y, x,  w, h, l);
...


Stl::StreamWriter writer("output.stl");
writer.write(builder.elements());

Stl::StreamReader reader("input.stl");
Stl::Entry entry;
while(reader.read(&entry))
   ...
   
```
