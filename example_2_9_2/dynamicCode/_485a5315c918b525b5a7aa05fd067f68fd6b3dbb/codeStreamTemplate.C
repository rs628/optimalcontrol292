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
#line 0 "/home/renu/example292/example_2_9_2/constant/f.#codeStream"
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
    void codeStream_485a5315c918b525b5a7aa05fd067f68fd6b3dbb
    (
        Ostream& os,
        const dictionary& dict
    )
    {
//{{{ begin code
        #line 0 "/home/renu/example292/example_2_9_2/constant/f.#codeStream"
const IOdictionary& d = static_cast<const IOdictionary&>(dict);
	    const fvMesh& mesh = refCast<const fvMesh>(d.db());

	    scalarField f(mesh.nCells(), 0.);
		//scalar pi = constant::mathematical::pi;

	    forAll(f, i)
	    {
		const scalar x = mesh.C()[i][0];
		const scalar y = mesh.C()[i][1];

		//f[i] = 2*pi*pi*sin(pi*x)*sin(pi*y) + sign(-sin(8*pi*x)*sin(8*pi*y));
                  f[i] = 0;// 1-min(1,max(0,(12*(Foam::pow((x-0.5),2)+Foam::pow((y-0.5),2))-(1/3)));
	    }

	    f.writeEntry("", os);
//}}} end code
    }
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //

