#include "Target.hpp"

using namespace tulip::hook;

Result<void*> Target::allocateArea(size_t size) {
	if (m_remainingOffset < size) {
		TULIP_UNWRAP(this->allocatePage());
	}

	auto ret = reinterpret_cast<size_t>(m_allocatedPage) + m_currentOffset;

	m_remainingOffset -= size;
	m_currentOffset += size;

	return Ok(reinterpret_cast<void*>(ret));
}

Result<> Target::writeMemory(void* destination, void* source, size_t size) {
	TULIP_UNWRAP_INTO(auto oldProtection, this->getProtection(destination));

	TULIP_UNWRAP(this->protectMemory(destination, size, this->getMaxProtection()));
	TULIP_UNWRAP(this->rawWriteMemory(destination, source, size));
	TULIP_UNWRAP(this->protectMemory(destination, size, oldProtection));

	return Ok();
}

void Target::closeKeystone(ks_engine* engine) {
	ks_close(m_keystone);

	m_keystone = nullptr;
}
ks_engine* Target::getKeystone() {
	return m_keystone;
}

void Target::closeCapstone(csh engine) {
	cs_close(&m_capstone);

	m_capstone = 0;
}
csh Target::getCapstone() {
	return m_capstone;
}