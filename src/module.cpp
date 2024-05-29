#include "module.h"
#include <module_export.h>

using namespace plugify;

namespace lm {
	InitResult TemplateLanguageModule::Initialize(std::weak_ptr<IPlugifyProvider> provider, const IModule& module) {
		// TODO: implement
		return InitResultData{};
	}

	void TemplateLanguageModule::Shutdown() {
		// TODO: implement
	}

	LoadResult TemplateLanguageModule::OnPluginLoad(const IPlugin& plugin) {
		// TODO: implement
		return ErrorData{ "Loading not implemented" };
	}

	void TemplateLanguageModule::OnPluginStart(const IPlugin& plugin) {
		// TODO: implement
	}

	void TemplateLanguageModule::OnPluginEnd(const IPlugin& plugin) {
		// TODO: implement
	}

	void TemplateLanguageModule::OnMethodExport(const IPlugin& plugin) {
		// TODO: implement
	}

	TemplateLanguageModule g_lm;

	extern "C"
	GOLM_EXPORT ILanguageModule* GetLanguageModule() {
		return &g_lm;
	}
}
