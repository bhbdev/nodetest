## nodetest


Simple tests using V8 Node.js C++ wrappers to create custom functions.


### Express / Node example using custom node extensions
```
node app.js 
```

#### ext/lib/
contains the built .node extensions precompiled for arch=arm64  on an M1 Macbook Pro



### Building node extensions
This requires having v8 and node includes available or installed on your PATH.

Check README found in each subdirectory of `nodeext/` for build notes. Requires `node-gyp` and configuration depends on your arch. Ex. arch=arm64