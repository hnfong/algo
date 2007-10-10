{ delays n seconds on the judge ( calibrated!! } }
procedure d(x : longint);
var i : longint;
begin
	for i := 1 to x * 67000000 do;
end;

{ gcd }
function gcd(a,b:integer):integer;
begin
   while (a>0) and (b>0) do
   begin
      if (a>b) then
	 a := a mod b
      else 
	b := b mod a;
   end;
   if (a=0) then
	gcd := b
   else
      gcd := a;
end; 
