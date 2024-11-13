#include "module.hpp"
#include <module_export.h>

using namespace plugify;

namespace lm {
	InitResult TemplateLanguageModule::Initialize(std::weak_ptr<IPlugifyProvider> provider, ModuleRef module) {
		// TODO: implement
		return InitResultData{};
	}

	void TemplateLanguageModule::Shutdown() {
		// TODO: implement
	}

	LoadResult TemplateLanguageModule::OnPluginLoad(PluginRef plugin) {
		// TODO: implement
		return ErrorData{ "Loading not implemented" };
	}

	void TemplateLanguageModule::OnPluginStart(PluginRef plugin) {
		// TODO: implement
	}

	void TemplateLanguageModule::OnPluginEnd(PluginRef plugin) {
		// TODO: implement
	}

	void TemplateLanguageModule::OnMethodExport(PluginRef plugin) {
		// TODO: implement
	}

	bool TemplateLanguageModule::IsDebugBuild() {
		return LM_IS_DEBUG;
	}

	TemplateLanguageModule g_lm;

	extern "C"
	LM_EXPORT ILanguageModule* GetLanguageModule() {
		return &g_lm;
	}
}
