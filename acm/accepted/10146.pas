program p10146;
const
	hc : array[0..11] of string[11] = (
	'',
	' ',
	'  ',
	'   ',
	'    ',
	'     ',
	'      ',
	'       ',
	'        ',
	'         ',
	'          ',
	'           '
	);
var
{
@JUDGE_ID: 20044WC 10146 PASCAL 
}
	k,n : longint;
	p,s  :string;
function same(x:longint):boolean;
var i : longint;
begin
	same := false;
	if (x > length(p)) or (x > length(s)) then exit;
	for i := 1 to x do begin
		if s[i] <> p[i] then exit;
	end;
	same := true;
end;

begin
	readln(n);
	readln;
	while n > 0 do begin
		readln(p);
		writeln(p);
		k := 0;
		while not eof do begin
			readln(s);
			if s = '' then break;
			inc(k);
			while (k>0) and (not same(k)) do dec(k);
			write(hc[k]);
			writeln(s);
			p := s;
		end;
		if n > 1 then writeln;
		dec(n);
	end;
end.

