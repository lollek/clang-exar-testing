# Clang-ExAr-Testing

This is a project skeleton for building clang plugins.

## Building
```
mkdir build
cd build
cmake ..
make
```

## Adding plugins
Create a folder under plugins, where you add any data you need. To build it automatically, you need to add a CMakeList.txt file (see the other plugin-folders for examples) to the folder. The plugins/CMakeLists.txt will automatically add your plugin to the make process.

## Running plugins
All plugins are joined to a single shared library. To run it in clang you can do either of these ways
```
$ clang -cc1 -load build/libexar.so -plugin name-of-plugin [... insert files or flags here ...]
$ clang -Xclang -load -Xclang build/libexar.so -Xclang -plugin -Xclang name-of-plugin  [... insert files or flags here ...]
```

If the plugins only generate warnings and do no care for building code, you should add the -fsyntax-only flag.

