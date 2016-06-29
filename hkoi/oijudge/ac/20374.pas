program expo;
var
	i,a,b,n : longint;
	d : int64;
begin
	readln(a);
	readln(b);
	readln(n);
        d := 1;
        for i := 31 downto 0 do begin
                d := (d*d) mod n;
                if ((b and (1 shl i)) shr i) = 1 then begin
                        d := (d*a) mod n;
                end;
        end;
        writeln(d);
end.
