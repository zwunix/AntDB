#ifndef EXEC_CLUSTER_H
#define EXEC_CLUSTER_H

#define EXEC_CLUSTER_FLAG_NEED_REDUCE		(1<<0)
#define EXEC_CLUSTER_FLAG_NEED_SELF_REDUCE	(1<<1)
#define EXEC_CLUSTER_FLAG_USE_MEM_REDUCE	(1<<2)
#define EXEC_CLUSTER_FLAG_USE_SELF_AND_MEM_REDUCE	0x7

struct Plan;
struct EState;
struct CopyStmt;

typedef void (*ClusterCustom_function)(StringInfo mem_toc);
#define ClusterTocSetCustomFun(toc, fun) ClusterTocSetCustomFunStr(toc, #fun)

extern Oid GetCurrentCnRdcID(const char *rdc_name);
extern void exec_cluster_plan(const void *splan, int length);
extern PlanState* ExecStartClusterPlan(Plan *plan, EState *estate
								, int eflags, List *rnodes);
extern List* ExecStartClusterCopy(List *rnodes, struct CopyStmt *stmt, StringInfo mem_toc, uint32 flag);
extern List *ExecStartClusterAuxPadding(List *rnodes, Node *stmt, StringInfo mem_toc, uint32 flag);

extern void ClusterTocSetCustomFunStr(StringInfo mem_toc, const char *proc);
extern List* ExecClusterCustomFunction(List *rnodes, StringInfo mem_toc, uint32 flag, bool read_only);

extern void ClusterRecvTableStat(const char *data, int length);
extern void SaveTableStatSnapshot(void);
extern bool SerializeTableStat(StringInfo buf);
extern void DestroyTableStateSnapshot(void);

#endif /* EXEC_CLUSTER_H */
