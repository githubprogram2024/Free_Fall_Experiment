//**********************************************************************************************
//************************ACQUIRING DATA FROM ARDUINO VIA EXCEL.********************************
//********************This version works for both 32-bit and 64-bit systems********************
//**********************************************************************************************

//******HARDWARE DEFINITIONS
#define LED  13
#define interruptPin  2

//*******VARIABLE DEFINITIONS
int option, i, ii = 0, j = 0, jj;                  
float T[100];


void setup() 
{
    Serial.begin(9600);
    pinMode(LED, OUTPUT); 
    Serial.println("LABEL,t(s),S(m),t(s),S(m)");
    // attachInterrupt(0, Time, CHANGE); //Activating external interrupt mode (Pin D2)
    attachInterrupt(digitalPinToInterrupt(interruptPin), Time, CHANGE);
}

void Time()// Function to capture time using external interrupt in microseconds
{
    T[j] = micros();
    j = j + 1;
}
void loop() 
{
    if (Serial.available() > 0)  
    {
        option = Serial.read();    
    }
    
    switch(option)
    {
        case 'A':
            digitalWrite(LED, HIGH);
            Serial.println("LABEL,t(s),S(m),t(s),S(m)");
            
            jj = 2; // Row Control
            for (i = 0; i < 19; i++)
            {
                Serial.print("CELL,SET,");   
                Serial.print('A'); // Specify the Column 
                Serial.print(jj);  // Specify the Row
                Serial.print(",");
                Serial.println((T[i] - T[0]) / 1000000, 4);
                Serial.print("CELL,SET,");
                Serial.print('B');          
                Serial.print(jj);
                Serial.print(",");
                Serial.println(i * 0.0193, 4);
                jj = jj + 1; // Row progression    
                // delay(100);
            }    

            j = 0;
            for (i = 0; i < 30; i++)
            {
                T[i] = 0; // RESET THE TIME STORAGE ARRAY
            }
            digitalWrite(LED, LOW);
            option = 100;       
            break;

        case 'B':   //************RESETTING COLUMNS A, B******************
            jj = 2;
            Serial.println("RESETROW");
            digitalWrite(LED, HIGH);
            
            for (i = 0; i < 19; i++)
            {  
                Serial.print("CELL,SET,");   
                Serial.print('A'); // Specify the Column 
                Serial.print(jj); // Specify the Row
                Serial.print(",");
                Serial.println(0);
                Serial.print("CELL,SET,");
                Serial.print('B');         
                Serial.print(jj);
                Serial.print(",");
                Serial.println(0);
                jj = jj + 1; // Row progression     
            }  

            digitalWrite(LED, LOW);
            option = 100;       
            break;

        case 'C': 
            digitalWrite(LED, HIGH);
            Serial.println("LABEL,t(s),S(m),t(s),S(m)");
            jj = 2; // Row Control
            for (i = 0; i < 19; i++)
            {
                Serial.print("CELL,SET,"); // Specifying the Cell
                Serial.print('C'); // Specify the Column  
                Serial.print(jj); // Specify the Row
                Serial.print(",");
                Serial.println((T[i] - T[0]) / 1000000, 4);
                Serial.print("CELL,SET,");
                Serial.print('D');          
                Serial.print(jj);
                Serial.print(",");
                Serial.println(i * 0.0193, 4);
                jj = jj + 1; // Row progression    
                // delay(100);
            }   
            Serial.println(" ");
            j = 0;
            for (i = 0; i < 30; i++)
            {
                T[i] = 0;
            }
            digitalWrite(LED, LOW);
            option = 100;       
            break;

        case 'D':    
            //************RESETTING THE SPREADSHEET******************
            ii = 0;
            jj = 2;
            Serial.println("RESETROW");
            digitalWrite(LED, HIGH);
            
            for (i = 0; i < 19; i++)
            {  
                Serial.print("CELL,SET,");   
                Serial.print('C');          
                Serial.print(jj);           
                Serial.print(",");
                Serial.println(0);
                Serial.print("CELL,SET,");
                Serial.print('D');          
                Serial.print(jj);
                Serial.print(",");
                Serial.println(0);
                jj = jj + 1; // Row progression     
            }  
            digitalWrite(LED, LOW);
            option = 100;
            break;

            case 'R':
            digitalWrite(LED, HIGH);
            
            for (i = 0; i < 19; i++)
            {
                Serial.print((T[i] - T[0]) / 1000000, 4);
                Serial.print(",");
                Serial.println(i * 0.0193, 4);   
            }    
                Serial.println("**********************");
                Serial.println("**********************");
                
                digitalWrite(LED, LOW);
                option = 100;       
                  break;

            

        case 'E':       //************RECEIVING PARAMETERS******************
            option = 100;
            break;

        default:
            delay(1);                
    }
}  
