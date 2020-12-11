#pragma once
#include <string>
#include <unordered_map>
#include "../Includes/WTSMarcos.h"

NS_OTP_BEGIN

class WtFilterMgr
{
public:
	WtFilterMgr():_filter_timestamp(0){}

	/*
	 *	�����źŹ�����
	 */
	void		load_filters(const char* fileName = "");

	/*
	 *	�Ƿ���Ϊ���Ա����˵���
	 *	����������Ǻ��ԵĻ�, �ͻ᷵��true, ������ض����λ, �ͻ᷵��false, ��Ŀ���λ��һ�����������Ĺ���ֵ
	 *
	 *	@sname		��������
	 *	@targetPos	Ŀ���λ, �Ը�����Ϊ׼
	 *	@isDiff		�Ƿ�������
	 *
	 *	return		�Ƿ���˵���, ������˵���, �óֲ־Ͳ������������Ŀ���λ
	 */
	bool		is_filtered_by_strategy(const char* straName, double& targetPos, bool isDiff = false);

	/*
	 *	�Ƿ���Ϊ���뱻���˵���
	 *	����������Ǻ��ԵĻ�, �ͻ᷵��true, ������ض����λ, �ͻ᷵��false, ��Ŀ���λ��һ�����������Ĺ���ֵ
	 *
	 *	@stdCode	��׼��Լ����
	 *	@targetPos	Ŀ���λ, �Ը�����Ϊ׼
	 *
	 *	return		�Ƿ���˵���, ������˵���, �óֲ־Ͳ������������Ŀ���λ
	 */
	bool		is_filtered_by_code(const char* stdCode, double& targetPos);

private:
	//////////////////////////////////////////////////////////////////////////
	//�źŹ�����
	typedef enum tagFilterAction
	{
		FA_Ignore,		//����, ��ά��ԭ�в�λ
		FA_Redirect,	//�ض���ֲ�, ��ͬ����ָ��Ŀ���λ
		FA_None = 99
	} FilterAction;

	typedef struct _FilterItem
	{
		std::string		_key;		//�ؼ���
		FilterAction	_action;	//���˲���
		double			_target;	//Ŀ���λ, ֻ�е�_actionΪFA_Redirect����Ч
	} FilterItem;

	typedef std::unordered_map<std::string, FilterItem>	FilterMap;
	FilterMap		_stra_filters;	//���Թ�����

	FilterMap		_exec_filters;	//���������, ������Լ�����Ʒ�ִ���, ͬһʱ��ֻ��һ����Ч, ��Լ�������ȼ�����Ʒ�ִ���

	std::string		_filter_file;	//�����������ļ�
	uint64_t		_filter_timestamp;	//�������ļ�ʱ���
};

NS_OTP_END
