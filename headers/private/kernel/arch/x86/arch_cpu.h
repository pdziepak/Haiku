/*
 * Copyright 2002-2009, Axel Dörfler, axeld@pinc-software.de.
 * Copyright 2012, Alex Smith, alex@alex-smith.me.uk.
 * Distributed under the terms of the MIT License.
 *
 * Copyright 2001-2002, Travis Geiselbrecht. All rights reserved.
 * Distributed under the terms of the NewOS License.
 */
#ifndef _KERNEL_ARCH_x86_CPU_H
#define _KERNEL_ARCH_x86_CPU_H


#ifndef _ASSEMBLER

#include <module.h>
#include <arch/x86/descriptors.h>

#ifdef __x86_64__
#	include <arch/x86/64/iframe.h>
#else
#	include <arch/x86/32/iframe.h>
#endif

#endif	// !_ASSEMBLER


// MSR registers (possibly Intel specific)
#define IA32_MSR_TSC					0x10
#define IA32_MSR_APIC_BASE				0x1b

#define IA32_MSR_MTRR_CAPABILITIES		0xfe
#define IA32_MSR_SYSENTER_CS			0x174
#define IA32_MSR_SYSENTER_ESP			0x175
#define IA32_MSR_SYSENTER_EIP			0x176
#define IA32_MSR_ENERGY_PERF_BIAS		0x1b0
#define IA32_MSR_MTRR_DEFAULT_TYPE		0x2ff
#define IA32_MSR_MTRR_PHYSICAL_BASE_0	0x200
#define IA32_MSR_MTRR_PHYSICAL_MASK_0	0x201

#define IA32_MSR_EFER					0xc0000080

// MSR EFER bits
// reference
#define IA32_MSR_EFER_SYSCALL			(1 << 0)
#define IA32_MSR_EFER_NX				(1 << 11)

// x86_64 MSRs.
#define IA32_MSR_STAR					0xc0000081
#define IA32_MSR_LSTAR					0xc0000082
#define IA32_MSR_FMASK					0xc0000084
#define IA32_MSR_FS_BASE				0xc0000100
#define IA32_MSR_GS_BASE				0xc0000101
#define IA32_MSR_KERNEL_GS_BASE			0xc0000102

// K8 MSR registers
#define K8_MSR_IPM						0xc0010055

// x86 features from cpuid eax 1, edx register
#define IA32_FEATURE_FPU	(1 << 0) // x87 fpu
#define IA32_FEATURE_VME	(1 << 1) // virtual 8086
#define IA32_FEATURE_DE		(1 << 2) // debugging extensions
#define IA32_FEATURE_PSE	(1 << 3) // page size extensions
#define IA32_FEATURE_TSC	(1 << 4) // rdtsc instruction
#define IA32_FEATURE_MSR	(1 << 5) // rdmsr/wrmsr instruction
#define IA32_FEATURE_PAE	(1 << 6) // extended 3 level page table addressing
#define IA32_FEATURE_MCE	(1 << 7) // machine check exception
#define IA32_FEATURE_CX8	(1 << 8) // cmpxchg8b instruction
#define IA32_FEATURE_APIC	(1 << 9) // local apic on chip
//							(1 << 10) // Reserved
#define IA32_FEATURE_SEP	(1 << 11) // SYSENTER/SYSEXIT
#define IA32_FEATURE_MTRR	(1 << 12) // MTRR
#define IA32_FEATURE_PGE	(1 << 13) // paging global bit
#define IA32_FEATURE_MCA	(1 << 14) // machine check architecture
#define IA32_FEATURE_CMOV	(1 << 15) // cmov instruction
#define IA32_FEATURE_PAT	(1 << 16) // page attribute table
#define IA32_FEATURE_PSE36	(1 << 17) // page size extensions with 4MB pages
#define IA32_FEATURE_PSN	(1 << 18) // processor serial number
#define IA32_FEATURE_CLFSH	(1 << 19) // cflush instruction
//							(1 << 20) // Reserved
#define IA32_FEATURE_DS		(1 << 21) // debug store
#define IA32_FEATURE_ACPI	(1 << 22) // thermal monitor and clock ctrl
#define IA32_FEATURE_MMX	(1 << 23) // mmx instructions
#define IA32_FEATURE_FXSR	(1 << 24) // FXSAVE/FXRSTOR instruction
#define IA32_FEATURE_SSE	(1 << 25) // SSE
#define IA32_FEATURE_SSE2	(1 << 26) // SSE2
#define IA32_FEATURE_SS		(1 << 27) // self snoop
#define IA32_FEATURE_HTT	(1 << 28) // hyperthreading
#define IA32_FEATURE_TM		(1 << 29) // thermal monitor
#define IA32_FEATURE_IA64	(1 << 30) // IA64 processor emulating x86
#define IA32_FEATURE_PBE	(1 << 31) // pending break enable

// x86 features from cpuid eax 1, ecx register
#define IA32_FEATURE_EXT_SSE3		(1 << 0) // SSE3
#define IA32_FEATURE_EXT_PCLMULQDQ	(1 << 1) // PCLMULQDQ Instruction
#define IA32_FEATURE_EXT_DTES64		(1 << 2) // 64-Bit Debug Store
#define IA32_FEATURE_EXT_MONITOR	(1 << 3) // MONITOR/MWAIT
#define IA32_FEATURE_EXT_DSCPL		(1 << 4) // CPL qualified debug store
#define IA32_FEATURE_EXT_VMX		(1 << 5) // Virtual Machine Extensions
#define IA32_FEATURE_EXT_SMX		(1 << 6) // Safer Mode Extensions
#define IA32_FEATURE_EXT_EST		(1 << 7) // Enhanced SpeedStep
#define IA32_FEATURE_EXT_TM2		(1 << 8) // Thermal Monitor 2
#define IA32_FEATURE_EXT_SSSE3		(1 << 9) // Supplemental SSE-3
#define IA32_FEATURE_EXT_CNXTID		(1 << 10) // L1 Context ID
//									(1 << 11) // Reserved
#define IA32_FEATURE_EXT_FMA		(1 << 12) // Fused Multiply Add
#define IA32_FEATURE_EXT_CX16		(1 << 13) // CMPXCHG16B
#define IA32_FEATURE_EXT_XTPR		(1 << 14) // xTPR Update Control
#define IA32_FEATURE_EXT_PDCM		(1 << 15) // Perfmon and Debug Capability
//									(1 << 16) // Reserved
#define IA32_FEATURE_EXT_PCID		(1 << 17) // Process Context Identifiers
#define IA32_FEATURE_EXT_DCA		(1 << 18) // Direct Cache Access
#define IA32_FEATURE_EXT_SSE4_1		(1 << 19) // SSE4.1
#define IA32_FEATURE_EXT_SSE4_2		(1 << 20) // SSE4.2
#define IA32_FEATURE_EXT_X2APIC		(1 << 21) // Extended xAPIC Support
#define IA32_FEATURE_EXT_MOVBE 		(1 << 22) // MOVBE Instruction
#define IA32_FEATURE_EXT_POPCNT		(1 << 23) // POPCNT Instruction
#define IA32_FEATURE_EXT_TSCDEADLINE (1 << 24) // Time Stamp Counter Deadline
#define IA32_FEATURE_EXT_AES		(1 << 25) // AES Instruction Extensions
#define IA32_FEATURE_EXT_XSAVE		(1 << 26) // XSAVE/XSTOR States
#define IA32_FEATURE_EXT_OSXSAVE	(1 << 27) // OS-Enabled XSAVE
#define IA32_FEATURE_EXT_AVX		(1 << 28) // Advanced Vector Extensions
#define IA32_FEATURE_EXT_F16C		(1 << 29) // 16-bit FP conversion
#define IA32_FEATURE_EXT_RDRND		(1 << 30) // RDRAND instruction
#define IA32_FEATURE_EXT_HYPERVISOR	(1 << 31) // Running on a hypervisor

// x86 features from cpuid eax 0x80000001, edx register (AMD)
// only care about the ones that are unique to this register
#define IA32_FEATURE_AMD_EXT_SYSCALL	(1 << 11) // SYSCALL/SYSRET
#define IA32_FEATURE_AMD_EXT_NX			(1 << 20) // no execute bit
#define IA32_FEATURE_AMD_EXT_MMXEXT		(1 << 22) // mmx extensions
#define IA32_FEATURE_AMD_EXT_FFXSR		(1 << 25) // fast FXSAVE/FXRSTOR
#define IA32_FEATURE_AMD_EXT_RDTSCP		(1 << 27) // rdtscp instruction
#define IA32_FEATURE_AMD_EXT_LONG		(1 << 29) // long mode
#define IA32_FEATURE_AMD_EXT_3DNOWEXT	(1 << 30) // 3DNow! extensions
#define IA32_FEATURE_AMD_EXT_3DNOW		(1 << 31) // 3DNow!

// some of the features from cpuid eax 0x80000001, edx register (AMD) are also
// available on Intel processors
#define IA32_FEATURES_INTEL_EXT			(IA32_FEATURE_AMD_EXT_SYSCALL		\
											| IA32_FEATURE_AMD_EXT_NX		\
											| IA32_FEATURE_AMD_EXT_RDTSCP	\
											| IA32_FEATURE_AMD_EXT_LONG)

// x86 defined features from cpuid eax 6, eax register
#define IA32_FEATURE_DTS	(1 << 0) //Digital Thermal Sensor
#define IA32_FEATURE_ITB	(1 << 1) //Intel Turbo Boost Technology
#define IA32_FEATURE_ARAT	(1 << 2) //Always running APIC Timer
#define IA32_FEATURE_PLN	(1 << 4) //Power Limit Notification
#define IA32_FEATURE_ECMD	(1 << 5) //Extended Clock Modulation Duty
#define IA32_FEATURE_PTM	(1 << 6) //Package Thermal Management

// x86 defined features from cpuid eax 6, ecx register
#define IA32_FEATURE_APERFMPERF	(1 << 0) //IA32_APERF, IA32_MPERF
#define IA32_FEATURE_EPB	(1 << 3) //IA32_ENERGY_PERF_BIAS

// x86 defined features from cpuid eax 7, ebx register
#define IA32_FEATURE_HLE	(1 << 4) // Hardware Lock Elision
#define IA32_FEATURE_RTM	(1 << 11) // Restricted Transactional Memory

// cr4 flags
#define IA32_CR4_PAE					(1UL << 5)
#define IA32_CR4_GLOBAL_PAGES			(1UL << 7)

// Memory type ranges
#define IA32_MTR_UNCACHED				0
#define IA32_MTR_WRITE_COMBINING		1
#define IA32_MTR_WRITE_THROUGH			4
#define IA32_MTR_WRITE_PROTECTED		5
#define IA32_MTR_WRITE_BACK				6

// EFLAGS register
#define X86_EFLAGS_CARRY						0x00000001
#define X86_EFLAGS_RESERVED1					0x00000002
#define X86_EFLAGS_PARITY						0x00000004
#define X86_EFLAGS_AUXILIARY_CARRY				0x00000010
#define X86_EFLAGS_ZERO							0x00000040
#define X86_EFLAGS_SIGN							0x00000080
#define X86_EFLAGS_TRAP							0x00000100
#define X86_EFLAGS_INTERRUPT					0x00000200
#define X86_EFLAGS_DIRECTION					0x00000400
#define X86_EFLAGS_OVERFLOW						0x00000800
#define X86_EFLAGS_IO_PRIVILEG_LEVEL			0x00003000
#define X86_EFLAGS_IO_PRIVILEG_LEVEL_SHIFT		12
#define X86_EFLAGS_NESTED_TASK					0x00004000
#define X86_EFLAGS_RESUME						0x00010000
#define X86_EFLAGS_V86_MODE						0x00020000
#define X86_EFLAGS_ALIGNMENT_CHECK				0x00040000
#define X86_EFLAGS_VIRTUAL_INTERRUPT			0x00080000
#define X86_EFLAGS_VIRTUAL_INTERRUPT_PENDING	0x00100000
#define X86_EFLAGS_ID							0x00200000

#define X86_EFLAGS_USER_FLAGS	(X86_EFLAGS_CARRY | X86_EFLAGS_PARITY \
	| X86_EFLAGS_AUXILIARY_CARRY | X86_EFLAGS_ZERO | X86_EFLAGS_SIGN \
	| X86_EFLAGS_DIRECTION | X86_EFLAGS_OVERFLOW)


// iframe types
#define IFRAME_TYPE_SYSCALL				0x1
#define IFRAME_TYPE_OTHER				0x2
#define IFRAME_TYPE_MASK				0xf


#ifndef _ASSEMBLER


struct X86PagingStructures;


typedef struct x86_mtrr_info {
	uint64	base;
	uint64	size;
	uint8	type;
} x86_mtrr_info;

typedef struct x86_optimized_functions {
	void 	(*memcpy)(void* dest, const void* source, size_t count);
	void*	memcpy_end;
	void 	(*memset)(void* dest, int value, size_t count);
	void*	memset_end;
} x86_optimized_functions;

typedef struct x86_cpu_module_info {
	module_info	info;
	uint32		(*count_mtrrs)(void);
	void		(*init_mtrrs)(void);

	void		(*set_mtrr)(uint32 index, uint64 base, uint64 length,
					uint8 type);
	status_t	(*get_mtrr)(uint32 index, uint64* _base, uint64* _length,
					uint8* _type);
	void		(*set_mtrrs)(uint8 defaultType, const x86_mtrr_info* infos,
					uint32 count);

	void		(*get_optimized_functions)(x86_optimized_functions* functions);
} x86_cpu_module_info;

// features
enum x86_feature_type {
	FEATURE_COMMON = 0,     // cpuid eax=1, ecx register
	FEATURE_EXT,            // cpuid eax=1, edx register
	FEATURE_EXT_AMD,        // cpuid eax=0x80000001, edx register (AMD)
	FEATURE_6_EAX,          // cpuid eax=6, eax registers
	FEATURE_6_ECX,          // cpuid eax=6, ecx registers
	FEATURE_7_0_EBX,		// cpuid eax=7 ecx=0, ebx register

	FEATURE_NUM
};

enum x86_vendors {
	VENDOR_INTEL = 0,
	VENDOR_AMD,
	VENDOR_CYRIX,
	VENDOR_UMC,
	VENDOR_NEXGEN,
	VENDOR_CENTAUR,
	VENDOR_RISE,
	VENDOR_TRANSMETA,
	VENDOR_NSC,

	VENDOR_NUM,
	VENDOR_UNKNOWN,
};


typedef struct arch_cpu_info {
	// saved cpu info
	enum x86_vendors	vendor;
	uint32				feature[FEATURE_NUM];
	char				model_name[49];
	const char*			vendor_name;
	int					type;
	int					family;
	int					extended_family;
	int					stepping;
	int					model;
	int					extended_model;

	struct X86PagingStructures* active_paging_structures;

	size_t				dr6;	// temporary storage for debug registers (cf.
	size_t				dr7;	// x86_exit_user_debug_at_kernel_entry())

	// local TSS for this cpu
	struct tss			tss;
#ifndef __x86_64__
	struct tss			double_fault_tss;
#endif
} arch_cpu_info;


#undef PAUSE
#define PAUSE() asm volatile ("pause;")

#define nop() __asm__ ("nop"::)

#define x86_read_cr0() ({ \
	size_t _v; \
	__asm__("mov	%%cr0,%0" : "=r" (_v)); \
	_v; \
})

#define x86_write_cr0(value) \
	__asm__("mov	%0,%%cr0" : : "r" (value))

#define x86_read_cr2() ({ \
	size_t _v; \
	__asm__("mov	%%cr2,%0" : "=r" (_v)); \
	_v; \
})

#define x86_read_cr3() ({ \
	size_t _v; \
	__asm__("mov	%%cr3,%0" : "=r" (_v)); \
	_v; \
})

#define x86_write_cr3(value) \
	__asm__("mov	%0,%%cr3" : : "r" (value))

#define x86_read_cr4() ({ \
	size_t _v; \
	__asm__("mov	%%cr4,%0" : "=r" (_v)); \
	_v; \
})

#define x86_write_cr4(value) \
	__asm__("mov	%0,%%cr4" : : "r" (value))

#define x86_read_dr3() ({ \
	size_t _v; \
	__asm__("mov	%%dr3,%0" : "=r" (_v)); \
	_v; \
})

#define x86_write_dr3(value) \
	__asm__("mov	%0,%%dr3" : : "r" (value))

#define invalidate_TLB(va) \
	__asm__("invlpg (%0)" : : "r" (va))

#define wbinvd() \
	__asm__("wbinvd")

#define out8(value,port) \
	__asm__ ("outb %%al,%%dx" : : "a" (value), "d" (port))

#define out16(value,port) \
	__asm__ ("outw %%ax,%%dx" : : "a" (value), "d" (port))

#define out32(value,port) \
	__asm__ ("outl %%eax,%%dx" : : "a" (value), "d" (port))

#define in8(port) ({ \
	uint8 _v; \
	__asm__ volatile ("inb %%dx,%%al" : "=a" (_v) : "d" (port)); \
	_v; \
})

#define in16(port) ({ \
	uint16 _v; \
	__asm__ volatile ("inw %%dx,%%ax":"=a" (_v) : "d" (port)); \
	_v; \
})

#define in32(port) ({ \
	uint32 _v; \
	__asm__ volatile ("inl %%dx,%%eax":"=a" (_v) : "d" (port)); \
	_v; \
})

#define out8_p(value,port) \
	__asm__ ("outb %%al,%%dx\n" \
		"\tjmp 1f\n" \
		"1:\tjmp 1f\n" \
		"1:" : : "a" (value), "d" (port))

#define in8_p(port) ({ \
	uint8 _v; \
	__asm__ volatile ("inb %%dx,%%al\n" \
		"\tjmp 1f\n" \
		"1:\tjmp 1f\n" \
		"1:" : "=a" (_v) : "d" (port)); \
	_v; \
})


#ifdef __cplusplus
extern "C" {
#endif

struct arch_thread;

#ifdef __x86_64__
void __x86_setup_system_time(uint64 conversionFactor,
	uint64 conversionFactorNsecs);
#else
void __x86_setup_system_time(uint32 conversionFactor,
	uint32 conversionFactorNsecs, bool conversionFactorNsecsShift);
#endif

void x86_context_switch(struct arch_thread* oldState,
	struct arch_thread* newState);
void x86_userspace_thread_exit(void);
void x86_end_userspace_thread_exit(void);
void x86_swap_pgdir(addr_t newPageDir);
void x86_fxsave(void* fpuState);
void x86_fxrstor(const void* fpuState);
void x86_noop_swap(void* oldFpuState, const void* newFpuState);
void x86_fxsave_swap(void* oldFpuState, const void* newFpuState);
addr_t x86_get_stack_frame();
uint64 x86_read_msr(uint32 registerNumber);
void x86_write_msr(uint32 registerNumber, uint64 value);
uint32 x86_count_mtrrs(void);
void x86_set_mtrr(uint32 index, uint64 base, uint64 length, uint8 type);
status_t x86_get_mtrr(uint32 index, uint64* _base, uint64* _length,
	uint8* _type);
void x86_set_mtrrs(uint8 defaultType, const x86_mtrr_info* infos,
	uint32 count);
void x86_init_fpu();
bool x86_check_feature(uint32 feature, enum x86_feature_type type);
void* x86_get_double_fault_stack(int32 cpu, size_t* _size);
int32 x86_double_fault_get_cpu(void);

void x86_invalid_exception(iframe* frame);
void x86_fatal_exception(iframe* frame);
void x86_unexpected_exception(iframe* frame);
void x86_hardware_interrupt(iframe* frame);
void x86_page_fault_exception(iframe* iframe);

#ifndef __x86_64__

void x86_fnsave(void* fpuState);
void x86_frstor(const void* fpuState);
void x86_fnsave_swap(void* oldFpuState, const void* newFpuState);

#endif


#ifdef __cplusplus
}	// extern "C" {
#endif

#endif	// !_ASSEMBLER

#endif	/* _KERNEL_ARCH_x86_CPU_H */
