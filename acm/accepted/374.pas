program expo;
{
	@JUDGE_ID: 20044WC 374 PASCAL "Modular Exponentation"
}
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
var
	a,b,c : longint;
begin
	while not eof do begin
	readln(a); readln(b); readln(c); readln;
	writeln(mod_exp(a,b,c));
	end;
end.

