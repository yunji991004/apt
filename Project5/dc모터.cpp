const int motorDirPin = 8; // L298 Input 3, L9110 A-IA
const int motorPWMPin = 9; // L298 Input 4, L9110 A-IB

/*
 *   ���� ���� �Լ�
 *  �Ƶ��̳�� L298�� ������ ���� ���� ���� ��
 *  ������ dir�� high�� �� ������, low�� �� ������
 *  �ӵ��� dir�� high�� ��, 255�� ����, 0�� �ְ�ӵ�
 *  low�� ��, 0�� ����, 255�� �ְ� �ӵ�
 */
void doMotor(bool dir, int vel) {
    digitalWrite(motorDirPin, dir);
    analogWrite(motorPWMPin, (dir) ? (255 - vel) : vel); // dir�� high�̸� 255-vel, low�̸� vel
}

void setup() {
    pinMode(motorDirPin, OUTPUT); // pinMode ������ digital�� �ʿ��ϰ� PWM�� ����� analog�� �ʿ� ����.
}

void loop() {
    // �ð�������� �����ϴٰ� �ְ�ӵ����� �ٽ� ����
    for (int i = 0; i < 255; i++) {
        doMotor(HIGH, i);
        delay(100);
    }
    for (int i = 255; i >= 0; i--) {
        doMotor(HIGH, i);
        delay(100);
    }

    // �ݽð�������� �����ϴٰ� �ְ�ӵ����� �ٽ� ����
    for (int i = 0; i < 255; i++) {
        doMotor(LOW, i);
        delay(100);
    }
    for (int i = 255; i >= 0; i--) {
        doMotor(LOW, i);
        delay(100);
    }
}