#include <Platform.hpp>
#include <platform/DefaultConvention.hpp>
#incude "../assembler/BaseAssembler.hpp"

using namespace tulip::hook;

DefaultConvention::~DefaultConvention() {}

void DefaultConvention::generateDefaultCleanup(BaseAssembler& a, AbstractFunction const& function) {}

void DefaultConvention::generateIntoDefault(BaseAssembler& a, AbstractFunction const& function) {}

void DefaultConvention::generateIntoOriginal(BaseAssembler& a, AbstractFunction const& function) {}

void DefaultConvention::generateOriginalCleanup(BaseAssembler& a, AbstractFunction const& function) {}

std::shared_ptr<DefaultConvention> DefaultConvention::create() {
	return std::make_shared<DefaultConvention>();
}
