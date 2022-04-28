> 1.เรื่องแสดงผล 
    1. ถ้า in_WtL=hi , in_WtH=hi  => display WATER_Lv=HIGH                OK
    2. ถ้า in_WtL=hi , in_WtH=low => display WATER_Lv= BETWEEN            OK
    3. in_WtL=low   , in_WtH=low => display WATER_Lv=LOW                 OK

> 2.เรื่อง ตั้งค่า OV_Temp ให้สั่ง RL1 ทำงาน        OK

> 3.เรื่อง LED
    1.ค่า Default เริ่มต้นให้ไฟดับ               OK
    2.ทำงานเป็น Output 5 สถานะตามรูป
       A red blink    >> OVER TEMP           OK
       
       B red solid    >> OVER Time       
       C yello blink  >> Oil   X            OK
       D yello solid  >> Fuel  X            OK
       E Green blink  >> SYSTEM Runing...   OK

> 4. HOUR.
