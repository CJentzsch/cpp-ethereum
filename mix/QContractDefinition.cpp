/*
	This file is part of cpp-ethereum.

	cpp-ethereum is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	cpp-ethereum is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file QContractDefinition.cpp
 * @author Yann yann@ethdev.com
 * @date 2014
 */

#include <QObject>
#include <libsolidity/CompilerStack.h>
#include <libsolidity/AST.h>
#include <libsolidity/Scanner.h>
#include <libsolidity/Parser.h>
#include <libsolidity/Scanner.h>
#include <libsolidity/NameAndTypeResolver.h>
#include "AppContext.h"
#include "QContractDefinition.h"
using namespace dev::solidity;
using namespace dev::mix;

QContractDefinition::QContractDefinition(dev::solidity::ContractDefinition const* _contract): QBasicNodeDefinition(_contract)
{
	std::vector<FunctionDefinition const*> functions = _contract->getInterfaceFunctions();
	for (unsigned i = 0; i < functions.size(); i++)
	{
		FunctionDefinition const* func = functions.at(i);
		m_functions.append(new QFunctionDefinition(func, i));
	}
}

