program expo;
function mod_exp(a,b,n: longint):longint;
var i : longint; d : int64;
begin
	d := 1;
	for i := 31 downto 0 do begin
		d := (d*d) mod n;
		if ((b and (1 shl i)) shr i) = 1 then begin
			d := (d*a) mod n;
		end;
	end;
	mod_exp := d;
end;

function is_pseudo_prime(n:longint):boolean;
const
	hc : array[1..25] of integer = (
		2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,87,97
	);
var
	i : longint;
begin
	for i := 1 to 25 do begin
		if hc[i] >= n then break;
		if mod_exp(hc[i],n-1,n) <> 1 then begin
			is_pseudo_prime := false;
			exit;
		end;
	end;
	is_pseudo_prime := true;
end;

function is_prime(n:longint):boolean;
var	 i : longint;
begin
	is_prime := false;
	for i := 2 to trunc(sqrt(n)) do begin
		if n mod i = 0 then exit;
	end;
	is_prime := true;
end;

var
	i : longint;
	np : longint;
	wr : longint;
begin
	np := 0;
	wr := 0;
	for i := 1 to 300000 do begin
	{writeln(i);}
	if i mod 10000 = 0 then writeln(i);
	if is_prime(i) xor is_pseudo_prime(i) then inc(wr);
	if is_prime(i) then inc(np);
	end;
	writeln(wr, ' out of ', np, ' where fscked up');
end.

