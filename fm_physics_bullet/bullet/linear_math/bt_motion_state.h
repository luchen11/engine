/*
Bullet Continuous Collision Detection and Physics Library
Copyright (c) 2003-2006 Erwin Coumans  http://continuousphysics.com/Bullet/

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, 
including commercial applications, and to alter it and redistribute it freely, 
subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#ifndef BT_MOTIONSTATE_H
#define BT_MOTIONSTATE_H

#include "bt_transform.h"

///The btMotionState interface class allows the dynamics world to synchronize and interpolate the updated world transforms with graphics
///For optimizations, potentially only moving objects get synchronized (using setWorldPosition/setWorldOrientation)
/*
����ʾ�����ϣ�MotionState
һ��ֻ������������������棬һ�����ֻ��Ϊ��ʾ�����ṩ���ݣ����ǣ�浽��ͼ���������ϵ����⣬
��Box2D�����������������ֱ����Ҫֱ�����������ʵ��ȥ��ѯλ�ã�Ȼ�������ʾ�����ַ�ʽ��Ȼ��
���������Ҹо��ǳ����ã���Ϊ������update��ȥ�������ֶ�����������Ϸ�߼�������Ҫ������������+
ͼ�����������ֵ����ݡ������Բο�Box2D��Cocos2D for iPhone�����ϣ����ң�������ȫû���ƶ�������
Ҳ�����һ�β�ѯ���ƶ�����������ʹ�Ż����Բ��ƶ�����Ҳ�ǽ��������β�ѯ��
BulletΪ�˽�������⣬�ṩ���µĽ��������MotionState����ʵ���ǵ������״̬�ı�ʱ�ṩһ�ֻ�
�������Ҿ�Bullet���ĵ���˵�������ֻص��������ʵ��Ĳ�ֵ���Ż���ʾ��ͨ�����ַ�������MotionState
���־��Ѿ����������ʾ�ĸ��£���������Ҫ��update���������ָ��µĴ��롣���ң�ע�⣬�����Ի
����״̬�ı�ʱ�Ż���лص���������ȫ�����˲�������������ʧ��
motion state �Ƕ���Ⱦ�����ṩ��һ���ӿ�, ������Ⱦ���������Ⱦ�����λ��.
*/
class btMotionState
{
public:
	virtual ~btMotionState()
	{
		
	}
	
	virtual void	getWorldTransform(btTransform& worldTrans ) const =0;

	//Bullet only calls the update of worldtransform for active objects
	virtual void	setWorldTransform(const btTransform& worldTrans)=0;
};

#endif //BT_MOTIONSTATE_H