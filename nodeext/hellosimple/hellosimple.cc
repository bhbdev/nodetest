#include <v8.h>
#include <node.h>

using namespace node;
using namespace v8;

static void hello(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Hello World").ToLocalChecked());
}



void init(Local<Object> exports)
{
    NODE_SET_METHOD(exports, "hello", hello);
}

NODE_MODULE(hellosimple, init)