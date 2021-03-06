#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/syscall.h>

#if defined HAVE_UNION_BPF_ATTR_LOG_BUF && defined __NR_bpf
# include <linux/bpf.h>

static const struct bpf_insn insns[] = {
	{ .code = BPF_JMP | BPF_EXIT }
};

static char log_buf[4096];

static int
map_create(void)
{
	union bpf_attr attr = {
		.key_size = 4,
		.value_size = 8,
		.max_entries = 256
	};
	return syscall(__NR_bpf, BPF_MAP_CREATE, &attr, sizeof(attr));
}

static int
map_any(int cmd)
{
	union bpf_attr attr = {
		.map_fd = -1,
		.key = 0xdeadbeef,
		.value = 0xbadc0ded
	};
	return syscall(__NR_bpf, cmd, &attr, sizeof(attr));
}

static int
prog_load(void)
{
	union bpf_attr attr = {
		.insn_cnt = sizeof(insns) / sizeof(insns[0]),
		.insns = (unsigned long) insns,
		.license = (unsigned long) "GPL",
		.log_level = 42,
		.log_size = sizeof(log_buf),
		.log_buf = (unsigned long) log_buf
	};
	return syscall(__NR_bpf, BPF_PROG_LOAD, &attr, sizeof(attr));
}

int
main(void)
{
	if (!map_create())
		return 77;
	printf("bpf\\(BPF_MAP_CREATE, "
	       "\\{map_type=BPF_MAP_TYPE_UNSPEC, key_size=4, value_size=8, max_entries=256\\}, "
	       "%u\\) += -1 .*\n",
		(unsigned) sizeof(union bpf_attr));

	if (!map_any(BPF_MAP_LOOKUP_ELEM))
		return 77;
	printf("bpf\\(BPF_MAP_LOOKUP_ELEM, "
	       "\\{map_fd=-1, key=0xdeadbeef\\}, %u\\) += -1 .*\n",
		(unsigned) sizeof(union bpf_attr));

	if (!map_any(BPF_MAP_UPDATE_ELEM))
		return 77;
	printf("bpf\\(BPF_MAP_UPDATE_ELEM, "
	       "\\{map_fd=-1, key=0xdeadbeef, value=0xbadc0ded, flags=BPF_ANY\\}, "
	       "%u\\) += -1 .*\n",
		(unsigned) sizeof(union bpf_attr));

	if (!map_any(BPF_MAP_DELETE_ELEM))
		return 77;
	printf("bpf\\(BPF_MAP_DELETE_ELEM, "
	       "\\{map_fd=-1, key=0xdeadbeef\\}, %u\\) += -1 .*\n",
		(unsigned) sizeof(union bpf_attr));

	if (!map_any(BPF_MAP_GET_NEXT_KEY))
		return 77;
	printf("bpf\\(BPF_MAP_GET_NEXT_KEY, "
	       "\\{map_fd=-1, key=0xdeadbeef\\}, %u\\) += -1 .*\n",
		(unsigned) sizeof(union bpf_attr));

	if (!prog_load())
		return 77;
	printf("bpf\\(BPF_PROG_LOAD, "
	       "\\{prog_type=BPF_PROG_TYPE_UNSPEC, insn_cnt=1, insns=%p, "
	       "license=\"GPL\", log_level=42, log_size=4096, log_buf=%p, "
	       "kern_version=0\\}, %u\\) += -1 .*\n",
		insns, log_buf, (unsigned) sizeof(union bpf_attr));

	return 0;
}

#else

int
main(void)
{
	return 77;
}

#endif
