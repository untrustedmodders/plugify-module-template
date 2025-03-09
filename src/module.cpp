#include "module.hpp"
#include <module_export.h>

using namespace plugify;

namespace lm {
	InitResult TemplateLanguageModule::Initialize(std::weak_ptr<IPlugifyProvider> provider, ModuleHandle module) {
		// TODO: implement
		return InitResultData{{.hasUpdate = false}};
	}

	void TemplateLanguageModule::Shutdown() {
		// TODO: implement
	}
	
	void TemplateLanguageModule::OnUpdate(plugify::DateTime dt) {
		
	}

	LoadResult TemplateLanguageModule::OnPluginLoad(PluginHandle plugin) {
		// TODO: implement
		return ErrorData{ "Loading not implemented" };
	}

	void TemplateLanguageModule::OnPluginStart(PluginHandle plugin) {
		// TODO: implement
	}

	void TemplateLanguageModule::OnPluginUpdate(PluginHandle plugin, plugify::DateTime dt) {
		// TODO: implement
	}

	void TemplateLanguageModule::OnPluginEnd(PluginHandle plugin) {
		// TODO: implement
	}

	void TemplateLanguageModule::OnMethodExport(PluginHandle plugin) {
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
