#include <plugify/language_module.h>
#include <plugify/module.h>
#include <plugify/plugin.h>

namespace lm {
	class TemplateLanguageModule final : public plugify::ILanguageModule {
	public:
		TemplateLanguageModule() = default;

		// ILanguageModule
		plugify::InitResult Initialize(std::weak_ptr<plugify::IPlugifyProvider> provider, plugify::ModuleRef module) override;
		void Shutdown() override;
		plugify::LoadResult OnPluginLoad(plugify::PluginRef plugin) override;
		void OnPluginStart(plugify::PluginRef plugin) override;
		void OnPluginEnd(plugify::PluginRef plugin) override;
		void OnMethodExport(plugify::PluginRef plugin) override;
	};
}
