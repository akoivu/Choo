#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace Choo {
	class CHOO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}


#define CHOO_CORE_ERROR(...) ::Choo::Log::getCoreLogger()->error(__VA_ARGS__)
#define CHOO_CORE_WARNING(...) ::Choo::Log::getCoreLogger()->warn(__VA_ARGS__)
#define CHOO_CORE_INFO(...) ::Choo::Log::getCoreLogger()->info(__VA_ARGS__)
#define CHOO_CORE_TRACE(...) ::Choo::Log::getCoreLogger()->trace(__VA_ARGS__)
#define CHOO_CORE_FATAL(...) ::Choo::Log::getCoreLogger()->fatal(__VA_ARGS__)

#define CHOO_ERROR(...) ::Choo::Log::getClientLogger()->error(__VA_ARGS__)
#define CHOO_WARNING(...) ::Choo::Log::getClientLogger()->warn(__VA_ARGS__)
#define CHOO_INFO(...) ::Choo::Log::getClientLogger()->info(__VA_ARGS__)
#define CHOO_TRACE(...) ::Choo::Log::getClientLogger()->trace(__VA_ARGS__)
#define CHOO_FATAL(...) ::Choo::Log::getClientLogger()->fatal(__VA_ARGS__)