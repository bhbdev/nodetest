#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>

using namespace node;
using namespace v8;


class HelloWorld: ObjectWrap
{
	
private:
	int m_count;
	
public:
	
	static v8::Persistent<v8::Function> constructor;
	static void Init(v8::Local<v8::Object> target)
	{
		v8::Isolate* isolate = target->GetIsolate();
		v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, New);
		tpl->SetClassName(v8::String::NewFromUtf8(isolate, "HelloWorld", v8::NewStringType::kNormal).ToLocalChecked());
		tpl->InstanceTemplate()->SetInternalFieldCount(1);

		NODE_SET_PROTOTYPE_METHOD(tpl, "hello", Hello);

		constructor.Reset(isolate, tpl->GetFunction(isolate->GetCurrentContext()).ToLocalChecked());
		target->Set(isolate->GetCurrentContext(),
					v8::String::NewFromUtf8(isolate, "HelloWorld", v8::NewStringType::kNormal).ToLocalChecked(),
					tpl->GetFunction(isolate->GetCurrentContext()).ToLocalChecked()).Check();
	}

	HelloWorld() : m_count(0)
	{
	}
	~HelloWorld()
	{
	}

	static void New(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		if (args.IsConstructCall()) {
			HelloWorld* hw = new HelloWorld();
			hw->Wrap(args.This());
			args.GetReturnValue().Set(args.This());
		} else {
			v8::Local<v8::Function> cons = v8::Local<v8::Function>::New(isolate, constructor);
			args.GetReturnValue().Set(cons->NewInstance(isolate->GetCurrentContext()).ToLocalChecked());
		}
	}

	static void Hello(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		v8::Local<v8::String> result = v8::String::NewFromUtf8(isolate, "Hello World", v8::NewStringType::kNormal).ToLocalChecked();
		args.GetReturnValue().Set(result);
	}
};

v8::Persistent<v8::Function> HelloWorld::constructor;

extern "C" {
	static void init (Handle<Object> target)
	{
		HelloWorld::Init(target);
	}
	
	NODE_MODULE(hello, init);
}
