#pragma once

#include "Generator.hpp"

#include <Platform.hpp>

namespace tulip::hook {

	class ArmV8HandlerGenerator : public HandlerGenerator {
	public:
		using HandlerGenerator::HandlerGenerator;

		Result<> generateHandler() override;
		Result<std::vector<uint8_t>> generateIntervener() override;
		Result<> generateTrampoline(RelocateReturn offsets) override;
		Result<RelocateReturn> relocateOriginal(uint64_t target) override;

		std::vector<uint8_t> handlerBytes(uint64_t address) override;
		std::vector<uint8_t> intervenerBytes(uint64_t address) override;
		std::vector<uint8_t> trampolineBytes(uint64_t address, size_t offset) override;

		void relocateInstruction(cs_insn* insn, uint64_t& trampolineAddress, uint64_t& originalAddress) override;
	};

	class ArmV8WrapperGenerator : public WrapperGenerator {
	public:
		using WrapperGenerator::WrapperGenerator;

		Result<void*> generateWrapper() override;
		Result<void*> generateReverseWrapper() override;

		std::vector<uint8_t> wrapperBytes(uint64_t address) override;
		std::vector<uint8_t> reverseWrapperBytes(uint64_t address) override;
	};
}
