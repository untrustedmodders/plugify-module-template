#include <plugify/language_module.hpp>
#include <plugify/method.hpp>
#include <plugify/module.hpp>
#include <plugify/plugin.hpp>

namespace lm {
	class TemplateLanguageModule final : public plugify::ILanguageModule {
	public:
		TemplateLanguageModule() = default;

		// ILanguageModule
		plugify::InitResult Initialize(std::weak_ptr<plugify::IPlugifyProvider> provider, plugify::ModuleHandle module) override;
		void Shutdown() override;
		void OnUpdate(plugify::DateTime dt) override;
		plugify::LoadResult OnPluginLoad(plugify::PluginHandle plugin) override;
		void OnPluginStart(plugify::PluginHandle plugin) override;
		void OnPluginUpdate(plugify::PluginHandle plugin, plugify::DateTime dt) override;
		void OnPluginEnd(plugify::PluginHandle plugin) override;
		void OnMethodExport(plugify::PluginHandle plugin) override;
		bool IsDebugBuild() override;
	};
}
