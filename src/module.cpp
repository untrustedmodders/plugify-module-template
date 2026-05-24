#include "module.hpp"
#include <module_export.h>

using namespace plugify;

namespace lm {
	Result<InitData> TemplateLanguageModule::Initialize(const Provider& provider, const Extension& module) {
		// TODO: implement
		return MakeError("Initialition not implemented");
	}

	Result<void> TemplateLanguageModule::Shutdown() {
		// TODO: implement
		return MakeError("Shutdown not implemented");
	}
	
	Result<void> TemplateLanguageModule::OnUpdate(std::chrono::milliseconds dt) {
		// TODO: implement
		return MakeError("Updating not implemented");
	}

	Result<LoadData> TemplateLanguageModule::OnPluginLoad(const Extension& plugin) {
		// TODO: implement
		return MakeError("Loading not implemented");
	}

	Result<void> TemplateLanguageModule::OnPluginStart(const Extension& plugin) {
		// TODO: implement
		return MakeError("Starting not implemented");
	}

	Result<void> TemplateLanguageModule::OnPluginUpdate(const Extension& plugin,std::chrono::milliseconds dt) {
		// TODO: implement
		return MakeError("Updating not implemented");
	}

	Result<void> TemplateLanguageModule::OnPluginEnd(const Extension& plugin) {
		// TODO: implement
		return MakeError("Ending not implemented");
	}

	Result<void> TemplateLanguageModule::OnMethodExport(const Extension& plugin) {
		// TODO: implement
		return MakeError("Exporting not implemented");
	}

	bool TemplateLanguageModule::IsDebugBuild() const noexcept {
		return LM_IS_DEBUG;
	}

	TemplateLanguageModule g_lm;

	extern "C"
	LM_EXPORT ILanguageModule* GetLanguageModule() {
		return &g_lm;
	}
}
