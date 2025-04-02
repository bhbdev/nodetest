
#include <v8.h>
#include <node.h>

using namespace std;
using namespace v8;

static void Say(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = args.GetIsolate();
    HandleScope scope(isolate);

    if (args.Length() < 1 || !args[0]->IsString()) {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Argument must be a string", NewStringType::kNormal).ToLocalChecked()));
        return;
    }

    String::Utf8Value str(isolate, args[0]);
    string input(*str);

    string response = "You said: " + input;
    Local<String> result = String::NewFromUtf8(isolate, response.c_str(), NewStringType::kNormal).ToLocalChecked();
    args.GetReturnValue().Set(result);
}

void Initialize(Local<Object> exports)
{
    NODE_SET_METHOD(exports, "say", Say);
}

NODE_MODULE(say, Initialize);
