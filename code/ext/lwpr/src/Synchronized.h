/**
 * Copyright 2012 Wangxr, vintage.wang@gmail.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef LWPR_SYNCHRONIZED_H__
#define LWPR_SYNCHRONIZED_H__
#include "LWPRType.h"
#include "IPCSEM.h"
#include "Mutex.h"
#include "RWMutex.h"
#include "Semph.h"
#include "Object.h"
#include "Var.h"

namespace LWPR
{
	class Synchronized : public LWPR::Object
	{
		typedef enum syn_type_e
		{
			SYN_IPCSEM,
			SYN_MUTEX,
			SYN_SEMPH,
		} SYN_TYPE_E;

	public:
		Synchronized(const IPCID_T id);
		Synchronized(Mutex &lock);
		Synchronized(Semph &lock);
		~Synchronized();

	private:
		SYN_TYPE_E m_synType;

		IPCID_T m_id;
		Mutex* m_pMutex;
		Semph* m_pSemph;
	};

	class SynchronizedRead : public LWPR::Object
	{
	public:
		SynchronizedRead(RWMutex &lock);
		~SynchronizedRead();

	private:
		RWMutex* m_pRWMutex;
	};

	class SynchronizedWrite : public LWPR::Object
	{
	public:
		SynchronizedWrite(RWMutex &lock);
		~SynchronizedWrite();

	private:
		RWMutex* m_pRWMutex;
	};

	DECLAREVAR(Synchronized);
	DECLAREVAR(SynchronizedRead);
	DECLAREVAR(SynchronizedWrite);
};

#endif // end of LWPR_SYNCHRONIZED_H__
