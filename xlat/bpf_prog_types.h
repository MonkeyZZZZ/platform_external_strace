/* Generated by ./xlat/gen.sh from ./xlat/bpf_prog_types.in; do not edit. */

static const struct xlat bpf_prog_types[] = {
#if !(defined(BPF_PROG_TYPE_UNSPEC) || (defined(HAVE_DECL_BPF_PROG_TYPE_UNSPEC) && HAVE_DECL_BPF_PROG_TYPE_UNSPEC))
# define BPF_PROG_TYPE_UNSPEC 0
#endif
 XLAT(BPF_PROG_TYPE_UNSPEC),
#if !(defined(BPF_PROG_TYPE_SOCKET_FILTER) || (defined(HAVE_DECL_BPF_PROG_TYPE_SOCKET_FILTER) && HAVE_DECL_BPF_PROG_TYPE_SOCKET_FILTER))
# define BPF_PROG_TYPE_SOCKET_FILTER 1
#endif
 XLAT(BPF_PROG_TYPE_SOCKET_FILTER),
#if !(defined(BPF_PROG_TYPE_KPROBE) || (defined(HAVE_DECL_BPF_PROG_TYPE_KPROBE) && HAVE_DECL_BPF_PROG_TYPE_KPROBE))
# define BPF_PROG_TYPE_KPROBE 2
#endif
 XLAT(BPF_PROG_TYPE_KPROBE),
#if !(defined(BPF_PROG_TYPE_SCHED_CLS) || (defined(HAVE_DECL_BPF_PROG_TYPE_SCHED_CLS) && HAVE_DECL_BPF_PROG_TYPE_SCHED_CLS))
# define BPF_PROG_TYPE_SCHED_CLS 3
#endif
 XLAT(BPF_PROG_TYPE_SCHED_CLS),
#if !(defined(BPF_PROG_TYPE_SCHED_ACT) || (defined(HAVE_DECL_BPF_PROG_TYPE_SCHED_ACT) && HAVE_DECL_BPF_PROG_TYPE_SCHED_ACT))
# define BPF_PROG_TYPE_SCHED_ACT 4
#endif
 XLAT(BPF_PROG_TYPE_SCHED_ACT),
 XLAT_END
};
