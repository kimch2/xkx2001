//Cracked by Roath
// huayu.c ���컨��

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int i, num;

	weapon = me->query_temp("weapon");

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���컨��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_skill("throwing") < 120 )
		return notify_fail("���ڽ���׶����Ϊ������������ʩչ�����컨�꡹��\n");

	if( me->query_skill("force") < 100 )
		return notify_fail("����ڹ���Ϊ���δ��������������ʩչ�����컨�꡹��\n");

	if( me->query("max_neili") <= 600 )
		return notify_fail("���������Ϊ���㣬����������ʩչ�����컨�꡹��\n");

	if( me->query("neili") <= 500 )
		return notify_fail("�����������������������ʩչ�����컨�꡹��\n");

	if( weapon->query_amount() < 15 ) 
		return notify_fail("����ʣ��İ�����Ŀ����ʩչ�����컨�꡹��\n");

	num = 4 + random(4);
	me->add("neili", -200);
	me->add("jingli", -50);

	message_vision(HIR "\n\n$N���λ������˳�������ͻȻʩչ�����컨�꡹����ö"+weapon->name()+"��ֱϮ����\n"
		       "б�䡢�����������»������Ұ��桢ǰ���ޣ����װ������$n��\n" NOR, me, target);

	for (i=1; i<num+1; i++) {
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        }

        return 1;
}