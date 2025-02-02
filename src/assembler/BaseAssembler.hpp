#pragma once

#include <stdint.h>
#include <string>
#include <unordered_map>
#include <vector>

namespace tulip::hook {

	struct AssemblerLabelUpdates {
		int64_t m_address;
		std::string m_name;
		uint8_t m_size;
	};

	class BaseAssembler {
	public:
		int64_t m_baseAddress;
		std::vector<uint8_t> m_buffer;
		std::unordered_map<std::string, int64_t> m_labels;
		std::vector<AssemblerLabelUpdates> m_labelUpdates;

		BaseAssembler(int64_t baseAddress);
		BaseAssembler(BaseAssembler const&) = delete;
		BaseAssembler(BaseAssembler&&) = delete;
		~BaseAssembler();

		int64_t currentAddress() const;
		// maybe use span?
		std::vector<uint8_t> const& buffer() const;

		void write8(int8_t value);
		void write16(int16_t value);
		void write32(int32_t value);
		void write64(int64_t value);

		void rewrite8(int64_t address, int8_t value);
		void rewrite16(int64_t address, int16_t value);
		void rewrite32(int64_t address, int32_t value);
		void rewrite64(int64_t address, int64_t value);

		void label(std::string const& name);

		virtual void updateLabels();
	};
}