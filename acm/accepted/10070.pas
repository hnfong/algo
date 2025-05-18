program p10070;
{
@JUDGE_ID:  20044WC 10070 PASCAL "DaP/DyP"
}
var
	i,j,k,t,n : longint;
	n4 : array[1..4] of longint;
	n11 : longint;
	n3 : longint;
	c : char;
	leap, hulu, bulu : boolean;
begin
	while not eof do begin
		for i := 1 to 4 do n4[i] := 0;
		n11 := 0; n3 := 0; n := 0;
		leap := false; hulu := false; bulu := false;

		while not eoln do begin
			inc(n);
			read(c);
			t := ord(c) - 48;

			if (n mod 2) = 1 then n11 := n11 - t else n11 := n11 + t;

			n3 := n3 + t;

			n4[4] := n4[3];
			n4[3] := n4[2];
			n4[2] := n4[1];
			n4[1] := t;
		end;
		readln;
		
		{ leap % 4 and ((not % 100) or % 400)     }
		if (((n4[1] + n4[2]*10) mod 4) = 0) and (( not ((n4[1]=0) and (n4[2]=0)) ) or (((n4[3] + n4[4]*10) mod 4) = 0))  then begin
			leap := true;
		end;
		{ hulu % 3 and %5 }
		if ((n3 mod 3) = 0) and ((n4[1] mod 5) = 0) then hulu := true;

		{ bulu leap and %5 and % 11 }
		if leap and ((n4[1] mod 5) = 0) and ((n11 mod 11) = 0) then bulu := true;
		if leap then writeln('This is leap year.');
		if hulu then writeln('This is huluculu festival year.');
		if bulu then writeln('This is bulukulu festival year.');
		if (not leap) and (not hulu) and (not bulu) then writeln('This is an ordinary year.');
		writeln;
	end;
end.
