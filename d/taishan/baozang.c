//Cracked by Roath
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������̩ɽ��һ����ʤ��������һ��״��ʨ�ӵľ�ʯ����Ϊʨ
���¡�������Ļ���Ҫ���ڶ�����Ķ�������Ҳ�����������ǹŴ�
�����ĵط���������һ�������ڵļ�̩ɽ����
LONG
	);

	set("exits", ([
		"westup" : __DIR__"weipin",
	]));

	set("objects",([
		__DIR__"npc/xiang-ke" : 1,
	]));

 	set("outdoors", "taishan");
	set("cost", 4);
	setup();
	replace_program(ROOM);
}
