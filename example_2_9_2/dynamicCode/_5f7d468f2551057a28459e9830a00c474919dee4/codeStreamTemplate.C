/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) YEAR AUTHOR,AFFILIATION
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Description
    Template for use with codeStream.

\*---------------------------------------------------------------------------*/

#include "dictionary.H"
#include "Ostream.H"
#include "Pstream.H"
#include "unitConversion.H"

//{{{ begin codeInclude
#line 0 "/home/renu/example292/example_2_9_2/0/yd.#codeStream"
#include "fvCFD.H"
//}}} end codeInclude

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

extern "C"
{
    void codeStream_5f7d468f2551057a28459e9830a00c474919dee4
    (
        Ostream& os,
        const dictionary& dict
    )
    {
//{{{ begin code
        #line 0 "/home/renu/example292/example_2_9_2/0/yd.#codeStream"
const IOdictionary& d = static_cast<const IOdictionary&>(dict);
	    const fvMesh& mesh = refCast<const fvMesh>(d.db());

	    scalarField yd(mesh.nCells(), 0.);
		scalar pi = constant::mathematical::pi;

	    forAll(yd, i)
	    {
		const scalar x = mesh.C()[i][0];
		const scalar y = mesh.C()[i][1];

		//yd[i] = x*y*sin(constant::mathematical::pi*x)*sin(constant::mathematical::pi*y);
		//yd[i] = sin(pi*x)*sin(pi*y) + sin(8*pi*x)*sin(8*pi*y) ;
		//Td[i] = sin(*x);   
                   yd[i] = -(142.0/3)+12*(   Foam::pow(x-0.5,2.0)+Foam::pow(y-0.5,2.0)  );  

	    }

	    yd.writeEntry("", os);
//}}} end code
    }
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //

