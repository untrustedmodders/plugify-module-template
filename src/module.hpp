#include <plugify/language_module.hpp>
#include <plugify/method.hpp>
#include <plugify/module.hpp>
#include <plugify/plugin.hpp>

namespace lm {
	class TemplateLanguageModule final : public plugify::ILanguageModule {
	public:
		TemplateLanguageModule() = default;

		// ILanguageModule
		plugify::Result<InitData> Initialize(const plugify::Provider& provider, const plugify::Extension& module) override;
		plugify::Result<void> Shutdown() override;
		plugify::Result<void> OnUpdate(std::chrono::milliseconds dt) override;
		plugify::Result<LoadData> OnPluginLoad(const plugify::Extension& plugin) override;
		plugify::Result<void> OnPluginStart(const plugify::Extension& plugin) override;
		plugify::Result<void> OnPluginUpdate(const plugify::Extension& plugin, std::chrono::milliseconds dt) override;
		plugify::Result<void> OnPluginEnd(const plugify::Extension& plugin) override;
		plugify::Result<void> OnMethodExport(const plugify::Extension& plugin) override;
		bool IsDebugBuild() const noexcept override;
	};
}
