#include "fvCFD.H"
// integrate in the interior

J = 0.5 *lambda.value()*gSum(  volField * (Foam::pow(y.internalField() - yd.internalField(), 2) + Foam::pow(u.internalField(), 2) )  );

//labelist patchesToIntegrate = mesh.boundaryMesh()[patchesToIntegrate];


   
forAll(patchesToIntegrate, i)
{   
    
    label patchi = mesh.boundaryMesh().findPatchID(patchesToIntegrate[i]);
    J += -12.0*gSum(mesh.magSf().boundaryField()[patchi] * (y.boundaryField()[patchi]) );
}





