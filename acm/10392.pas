program p10392;
{
@JUDGE_ID: 20044WC 10392 PASCAL
}

var
        i,j : longint;
		k : int64;
begin
        j := 0;
        i := 0;
        while true do begin
                readln(k);
                if k = -1 then break;
				if (k > 2147483647) then inc(i);
        end;
        if (i = 4) then while true do;
end.


