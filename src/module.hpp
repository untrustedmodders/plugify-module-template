#include <plugify/language_module.hpp>
#include <plugify/module.hpp>
#include <plugify/plugin.hpp>

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
		bool IsDebugBuild() override;
	};
}
