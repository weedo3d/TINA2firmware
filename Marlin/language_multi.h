/**
* Copyright (C) 2019 WEEDO3D Perron
*/

/**
* 多国语言字符定义
* 数组中元素对应语言如下：
* Multi-language character definition
* The corresponding language of the elements in the array is as follows:
* 0 - EN / English
* 1 - CN / Chinese
* 2 - FR / French
* 3 - DE / German
* 4 - ES / Spanish
* 5 - IT / Italy
* 6 - KANA / Japanese
* 7 - PT / Portugal
* 8 - NL / Dutch
* 9 - TR / Turkish
* 10- KR / Korea
* 11- RU / Russian
*/

#ifndef LANGUAGE_MULTI_H
#define LANGUAGE_MULTI_H

const char MWELCOME_MSG[12][20] PROGMEM = {
	" Ready.",
	"\xa4\xa5\xa6\xa7",			// 准备就绪
	" Prete.",
	" Bereit",
	" listo.",
	" pronto.",
	" ready.",
	" pronta.",
	" gereed.",
	" hazır.",
	" Ready.",		// Ready.
	" готов."
};

const char MMSG_WATCH [12][41] PROGMEM = {	
	"Info screen",
	"\xec\xed\xee\xef",			// 信息界面 
	"Ecran infos",
	"Info",
	"Pantalla informacion",
	"Guarda",
	"\xbc\xde\xae\xb3\xce\xb3\xb6\xde\xd2\xdd",
	"Monitorizar",
	"Info scherm",
	"Bilgi Ekrani",
	"\xb4\xee \xe0\xaf",		// 상태 정보
	"Информационный экран",
};

const char MMSG_PREPARE[12][24] PROGMEM = {
	"Prepare",
	"\xa4\xa5\xee\xef",			// 准备界面		
	"Preparer",
	"Vorbereitung",
	"Preparar",
	"Prepara",
	"\xbc\xde\xad\xdd\xcb\xde\xbe\xaf\xc3\xb2",
	"Preparar",
	"Voorbereiden",
	"Hazirlik",
	"\xe3\xb1 \xda\xc4",		// 준비 작업
	"Подготовить",
};

const char MMSG_CONTROL[12][20] PROGMEM = {
	"Control",
	"\xd8\xd9\xee\xef",			// 控制界面		
	"Controle",
	"Einstellungen",
	"Control",
	"Controllo",
	"\xba\xdd\xc4\xdb\xb0\xd9",                                    // ｺﾝﾄﾛｰﾙ (Control)
	"Controlo",
	"Control",
	"Kontrol",
	"\xe1\xc2",		// 제어	
	"Настройки",
};

const char MMSG_CARD_MENU[12][31] PROGMEM = {
	"Print from SD",
	"SD\xa8\xee\xef",			// SD卡界面		
	"Imprimer de SD",
	"SD-Karte",
	"Imprimir desde SD",
	"Stampa da SD",
	"SD\xb6\xb0\xc4\xde\xb6\xd7\xcc\xdf\xd8\xdd\xc4",
	"Imprimir do SD",
	"Print van SD",
	"SD den Yazdir",
	"SD\xed\x99 \xeb\x9e",		// SD카드 출력	
	"Печать с SD карты",
};

const char MMSG_FILAMENTIN[12][37] PROGMEM = {
	"Auto Feed Filament",
	"\xe4\xab\x92\x94     ",			// 载入料丝		
	"Charger le filament",
	"Filament laden",
	"entrada de filamento",
	"Carica filamento",
	"\xcc\xb2\xd7\xd2\xdd\xc4\x20\xb2\xdd",
	"Alimente Filament",
	"Auto Feed Filament",
	"Yem Filamenti",
	"\xf7\x9c\xa0\xf2 \xb3\xd8",			// 필라멘트 삽입		
	"Загрузка филамента",
};

const char MMSG_FILAMENTOUT[12][31] PROGMEM = {
	"Auto Retract Filament",
	"\x93\xe4\x92\x94     ",			// 卸载料丝		
	"Decharger le filament",
	"Filament entladen",
	"retraccion filamento",
	"Scarica Filament",
	"\xcc\xb2\xd7\xd2\xdd\xc4\x20\xb1\xb3\xc4",
	"Retrair Filamento",
	"Auto Retract Filament",
	"Filamenti Geri Cek",
	"\xf7\x9c\xa0\xf2 \xe9\xeb",		// 필라멘트 추출	
	"Авто Втягивание",
};

const char MMSG_MOVE_AXIS[12][32] PROGMEM = {
	"Move axis",
	"\xc1\xb2\xce",			// 移动轴		
	"Deplacer l'axe",
	"Bewegen",
	"Mover ejes",
	"Muovi Asse",
	"\xbc\xde\xb8\xb2\xc4\xde\xb3",
	"Mover eixo",
	"As verplaatsen",
	"Eksen Yonet",
	"\xea \xd4\x97",			// 축 이동
	"Движение по осям",
};

const char MMSG_AUTO_HOME[12][27] PROGMEM = {
	"Auto home",
	"\xbb\xbc\xbd",			// 回原点	
	"Retour origine",
	"Home",
	"Auto Inicio",
	"Auto Home",
	"\xb9\xde\xdd\xc3\xdd\xcc\xaf\xb7",
	"Ir para origem",
	"Auto home",
	"Eksenleri Sifirla",
	"\xd0\xd1\xec",			// 원위치
	"Авто парковка",
};

const char MMSG_LEVEL_BED[12][33] PROGMEM = {
	"Level bed",
	"\xb1\xb2\xcf\xd0",			// 自动调平		
	"Mise a niveau",
	"Bett nivellieren",
	"Nivelar plataforma",
	"Livella piano",
	"\xcd\xde\xaf\xc4\xde\xda\xcd\xde\xd8\xdd\xb8\xde",
	"Cama nivelada",
	"Level bed",
	"Seviye yatagi",
	"\xca\xf1\x9d\xad",			// 오토레벨
	"Калибровать стол",
};

const char MMSG_DISABLE_STEPPERS[12][30] PROGMEM = {
	"Disable steppers",
	"\xb5\xb6\xb7\xb8\xb9\xba",			// 关闭步进电机
	"Desactiv le pas a pas",
	"Motoren deaktivieren",
	"Apagar motores",
	"Disabilita Motori",
	"\xd3\xb0\xc0\xb0\xc3\xde\xdd\xb9\xde\xdd\x20\xb5\xcc",
	"Desactivar motores",
	"Motoren uit",
	"Motorlari Durdur",
	"\xa0\xf0 \xe4\xe6",			// 모터 중지
	"Выкл. двигатели",
};

const char MMSG_WELCOME_MENU[12][24] PROGMEM = {
	"Wizard",
	"\xa2\xa3\xee\xef",			// 向导界面		
	"Lancer la config.",
	"Magier",
	"Wizzard",
	"procedura guidata",
	"\xb3\xb4\xb9\xb6",				// ウエルカム
	"Usando o assistente",
	"De wizard gebruiken",
	"Sihirbazı kullanma",
	"\xa0﻿\xab\xb2",			// 마법사
	"колдун",
};

const char MMSG_MAIN[12][20] PROGMEM = {
	"Main",
	"\xae\xaf\xb0",			// 主菜单 		
	"Menu",
	"Hauptmenu",
	"Menu principal",
	"Menu principale",
	"\xd2\xb2\xdd",
	"Menu principal",
	"Hoofdmenu",
	"Ana",
	"\xa0\xd6",			// 메인
	"Меню",
};

const char MMSG_TEMPERATURE[12][24] PROGMEM = {
	"Temperature",
	"\xc9\xd2\xbe\xbf",			// 温度设置		
	"Temperature",
	"Temperatur",
	"Temperatura",
	"Temperatura",
	"\xb5\xdd\xc4\xde",
	"Temperatura",
	"Temperatuur",
	"Sicaklik",
	"\xcb\x96",			// 온도	
	"Температура",
};

const char MMSG_ZPROBE_ZOFFSET[12][20] PROGMEM = {
	"Z Offset Setting",
	"\xbe\xbfZ\xce\xc0\xc1",			// 设置Z轴偏移 		
	"Z Offset",
	"Z Versatz",
	"Desfase Z",
	"Z Offset",
	"Z\xb5\xcc\xbe\xaf\xc4",
	"Desvio Z",
	"Z Offset",
	"Z Offset",
	"Z \xcc\xb8",				// Z 옵셋
	"Смещение Z",
};

const char MMSG_NETWORK_MENU[12][20] PROGMEM = {
	"Wifi Network",
	"\x99\x9a\xbe\xbf",			// 网络设置 		
	"Reseau Wifi",
	"WiFi-Netzwerk",
	"red Wifi",
	"Rete Wifi",
	"Wifi Network",
	"Rede Wi-Fi",
	"Wifi netwerk",
	"Wifi Agi",
	"Wifi Network",
	"Сеть Wi-Fi",
};

const char MMSG_NETWORK_IP[12][22] PROGMEM = {
	"Show IP",
	"\x97\x98\x99\x9aIP\x9b\x9c",			// 显示网络IP地址 		
	"Afficher l'adresse IP",
	"IP-Adresse anzeigen",
	"Mostrar direccion IP",
	"Mostra indirizzo IP",
	"Show IP",
	"Mostrar IP",
	"Toon IP-adres",
	"IP Adresini Goster",
	"IP \xe0\xaf",			// IP 정보 	
	"Показать IP",
};

const char MMSG_NETWORK_INFO[12][30] PROGMEM = {
	"Wifi Device Info",
	"\x97\x98Wifi\xbe\xa5\xec\xed",			// 显示Wifi设备信息 		
	"Info appareil",
	"WLAN-Gerateinfo",
	"dispositivo wifi",
	"informazioni wifi",
	"Wifi Device Info",
	"Informacao Wifi",
	"Wifi apparaatinfo",
	"Wifi Cihaz Bilgisi",
	"WiFi \xe0\xaf",			// WiFi 정보 	
	"Информация о Wifi",
};

const char MMSG_NETWORK_CONFIG[12][35] PROGMEM = {
	"Connect to Wifi",
	"\xbe\xbfWifi\x99\x9a      ",			// 设置wifi网络 		
	"Se connecter au Wifi",
	"Verbinden Sie Wifi",
	"Conectarse a wifi",
	"Connetti a Wifi",
	"Connect to Wifi",
	"Conecte-se a Wifi",
	"Wifi Config",
	"Wifi'a baglan",
	"WiFi \xc7\x86",			// WiFi 연결
	"Подключиться к Wi-Fi",
};

const char MMSG_NETWORK_OTA[12][26] PROGMEM = {
	"Wifi OTA Update",
	"Wifi\xbe\xa5OTA",			// Wifi设备OTA 		
	"Mise a jour Wifi OTA",
	"Wifi OTA Update",
	"dispositivo wifi ota",
	"Aggiornamento OTA",
	"Wifi OTA Update",
	"Atualizacao OTA",
	"Wifi OTA Update",
	"OTA Guncellemesi",
	"WiFi FW \xc4\x95\xd4\xf2",			// WiFi FW 업데이트	
	"OTA Обновление",
};

const char MMSG_NETWORK_CONFIG_1[12][37] PROGMEM = {
	"Open the App",
	"\xca\xb3 APP \xb8\xabWIFI\xbe\xbf",			// 打开APP进入WIFI设置 		
	"Ouvrez l'application",
	"Offnen Sie die App",
	"Abre la aplicacion",
	"Apri l'app",
	"Open the App",
	"Abra o aplicativo",
	"Open de app",
	"Uygulamayi Ac",
	"\xc1 \xbe\xfa",			// 앱 실행
	"Открыть приложение",
};

const char MMSG_NETWORK_CONFIG_2[12][31] PROGMEM = {
	"Goto Wifi Setting",
	"  \x8a\xabWifi\x99\x9a\x88\x89",			// 输入WIFI网络密码 		
	"Aller au menu wifi",
	"Zum Wifi-Menu",
	"en configuracion wifi",
	"Vai al menu Wifi",
	"Goto Wifi Setting",
	"Goto Wifi Setting",
	"Goto Wifi Instelling",
	"Wifi Ayarina Git",
	"WiFi \xb6\xe0",			// WiFi 설정	
	"Goto Wi-Fi Настройка",
};

const char MMSG_NETWORK_CONFIG_3[12][35] PROGMEM = {
	"Input Wifi Password",
	"  \x9d\x85\x86\x87 5G Wifi",			// 不要使用5G Wifi 		
	"Saisir mot de passe",
	"Passwort eingeben",
	"Contrasena de entrada",
	"Inserire password",
	"Input Wifi Password",
	"entrada Wifi Password",
	"Input Wifi Password",
	"Wifi Sifre Gir",
	"WiFi \xbf\xfb\xd8\x9e",				// WiFi 암호입력	
	"Введите пароль Wi-Fi",
};

const char MMSG_NETWORK_CONFIG_4[12][34] PROGMEM = {
	"5G Wifi not support",
	" ",					
	"pas utiliser 5G Wifi",
	"kein 5G Wifi",
	"Wifi 5G no soporta",
	"5G Wifi non supporta",
	"5G Wifi not support",
	"5G Wifi nao suporta",
	"geen steun 5G Wifi",
	"5G Wifi desteklemiyor",
	"5Ghz WiFi \xa0\xe6\xd0",			// 5Ghz WiFi 미지원
	"5G Wi-Fi не поддержка",
};

const char MMSG_NETWORK_OTA_MENU[12][33] PROGMEM = {
	"OTA UPDATING...",
	"OTA UPDATING...",			
	"MISE A JOUR OTA ...",
	"OTA AKTUALISIEREN ...",
	"OTA ACTUALIZANDO ...",
	"AGGIORNAMENTO OTA ...",
	"OTA UPDATING...",
	"OTA ATUALIZANDO ...",
	"OTA UPDATING ...",
	"OTA GÜNCELLEME ...",
	"FW \xc4\x95\xd4\xf2 \xe4...",			// FW 업데이트 중...	
	"ОТА ОБНОВЛЕНИЕ ...",
};

const char MMSG_NETWORK_OTA_1[12][30] PROGMEM = {
	"Don't turn off power",
	"\x9d\x85\xb5\xb6\xb9\xcb",			// 不要关闭电源		
	"ne pas eteindre",
	"Macht weiter so",
	"No apague el poder",
	"continua ad accendere",
	"Don't turn off power",
	"Nao desligue a energ-",
	"Niet uitschakelen uit",
	"Gucu kapatmayın",
	"\xdf\xd0\xd2 \x8e\xe6 \xa0\xb7\xce",				// 전원을 끄지 마세요	
	"Подожди минуту",
};

const char MMSG_NETWORK_OTA_2[12][22] PROGMEM = {
	"Wait a minute",
	" ",				
	"Attends une minute",
	"Warte eine Minute",
	"Espera un minuto",
	"Apetta un minuto",
	"Wait a minute",
	"ia e espere um minuto",
	"en wacht een minuut",
	"Bir dakika bekle",
	"\xdb\xbd \x8b\x92\xa0\xb7\xce.",			// 잠시 기다리세요.
	" ",
};

const char MMSG_UPLOADING_1[12][22] PROGMEM = {
	"Downloading:",
	"\x82\x83\x84\xe4      ",			// 正在下载	
	"Telechargement:",
	"Wird heruntergeladen:",
	"Descargando:",
	"Download:",
	"Downloading:",
	"Baixando:",
	"Downloaden:",
	"Indiriyor:",
	"\x92\xcf\x9f\x99 \xe4:",			// 다운로드 중:
	"Загрузка:",
};

const char MMSG_UPLOADING_FAIL[12][22] PROGMEM = {
	"Download Fail",
	"\x84\xe4\x9f\x9e       ",			// 下载失败		
	"Telecharger Fail",
	"Scheitern",
	"Error de descarga",
	"Scarica Fail",
	"Download Fail",
	"Falha no download",
	"Downloaden mislukt",
	"Indiriyor:",
	"\x92\xcf\x9f\x99 \xbe\xf5",			// 다운로드 실패	
	"Скачать Fail",
};

const char MMSG_LANGUAGE_MENU[12][26] PROGMEM = {
	"Language",
	"\x80\x81\xbe\xbf       ",			// 语言设置		
	"La langue",
	"Sprache",
	"Idioma",
	"linguaggio",
	"Language",
	"Lingua",
	"Taal",
	"Dil",
	"\xc3\xc2 \xb6\xe0",			// 언어 설정		
	"формулировки",
};

const char MMSG_LANGUAGE_EN[12][22] PROGMEM = {
	"English",
	"English",					
	"Anglais",
	"Englisch",
	"Ingles",
	"Inglese",
	"English",
	"Ingles",
	"Engels",
	"Ingilizce",
	"English",
	"английский",
};

const char MMSG_LANGUAGE_CN[12][20] PROGMEM = {
	"Chinese",
	"Chinese",				
	"Chinoise",
	"Chinesisch",
	"Chino",
	"Cinese",
	"Chinese",
	"Chines",
	"Chinese",
	"Cince",
	"Chinese",
	"Китайский",
};

const char MMSG_LANGUAGE_FR[12][24] PROGMEM = {
	"French",
	"French",				
	"Francais",
	"Franzosisch",
	"Frances",
	"Francese",
	"French",
	"Frances",
	"Frans",
	"Fransızca",
	"French",
	"Французский",
};

const char MMSG_LANGUAGE_DE[12][20] PROGMEM = {
	"German",
	"German",					
	"Allemand",
	"Deutsche",
	"Aleman",
	"Tedesca",
	"German",
	"Alemao",
	"Duits",
	"Almanca",
	"German",
	"Немецкий",
};

const char MMSG_LANGUAGE_ES[12][20] PROGMEM = {
	"Spanish",
	"Spanish",					
	"Espagnol",
	"Spanisch",
	"Espanol",
	"Spagnola",
	"Spanish",
	"Espanhol",
	"Spaans",
	"Ispanyol",
	"Spanish",
	"испанский",
};

const char MMSG_LANGUAGE_IT[12][20] PROGMEM = {
	"Italian",
	"Italian",				
	"Italienne",
	"Italienisch",
	"Italiano",
	"Italiana",
	"Italian",
	"Italiano",
	"Italiaans",
	"Italyan",
	"Italian",
	"итальянец",
};

const char MMSG_LANGUAGE_KANA[12][20] PROGMEM = {
	"Japanese",
	"Japanese",
	"Japonais",
	"Japanisch",
	"Japonesa",
	"Giapponese",
	"Japanese",
	"Japones",
	"Japans",
	"Japonca",
	"Japanese",
	"Японский",
};

const char MMSG_LANGUAGE_PT[12][22] PROGMEM = {
	"Portugal",
	"Portugal",
	"Le Portugal",
	"Portugal",
	"Portugues",
	"Portogallo",
	"Portugal",
	"Portugal",
	"Portugal",
	"Portekiz",
	"Portugal",
	"Португалия",
};

const char MMSG_LANGUAGE_NL[12][24] PROGMEM = {
	"Dutch",
	"Dutch",
	"Neerlandais",
	"Niederlandisch",
	"Holandes",
	"Olandese",
	"Dutch",
	"Holandes",
	"Nederlands",
	"Flemenkce",
	"Dutch",
	"Голландский",
};

const char MMSG_LANGUAGE_RU[12][20] PROGMEM = {
	"Russian",
	"Russian",
	"Russe",
	"Russisch",
	"Ruso",
	"Russo",
	"Russian",
	"Russo",
	"Russisch",
	"Rusca",
	"Russian",
	"русский",
};

const char MMSG_LANGUAGE_TR[12][20] PROGMEM = {
	"Turkish",
	"Turkish",
	"Turc",
	"Turkisch",
	"Turco",
	"Turco",
	"Turkish",
	"Turco",
	"Turks",
	"Turk",
	"Turkish",
	"турецкий",
};

const char MMSG_LANGUAGE_KR[12][20] PROGMEM = {
	"Korean",
	"Korean",
	"Coreen",
	"Koreanisch",
	"Coreano",
	"Coreano",
	"Korean",
	"Coreano",
	"Koreaans",
	"Koreli",
	"Korean",
	"Корейский",
};

const char MMSG_MACHINE_INFO[12][20] PROGMEM = {
	"Machine Info",
	"\xbe\xa5\xec\xed     ",			// 设备信息	
	"Info",
	"Maschineninfo",
	"Informacion",
	"Informazione",
	"Machine Info",
	"Em formacao",
	"Machine-info",
	"Makine Bilgisi",
	"\xdc\xec \xe0\xaf",			// 장치 정보	
	"Версия",
};

const char MMSG_INFO_MACHINE[12][20] PROGMEM = {
	"Machine: ",
	"\xbe\xa5: ",			// 设备	
	"Machine: ",
	"Maschine: ",
	"Maquina: ",
	"Macchina: ",
	"Machine: ",
	"Maquina: ",
	"Machine: ",
	"Makine: ",
	"\xdc\xec: ",			// 장치: 
	"Машина: ",
};

const char MMSG_INFO_VERSION[12][20] PROGMEM = {
	"Version: ",
	"\x95\x96: ",			// 版本	
	"Version: ",
	"Ausfuhrung: ",
	"Version: ",
	"Versione: ",
	"Version: ",
	"Versao: ",
	"Versie: ",
	"Surum: ",
	"\xaa\xdf: ",			// 버전:
	"Версия: ",
};

const char MMSG_RESTORE_DEFAULT[12][38] PROGMEM = {
	"Restore default",
	"\xe7\xe8\xad\xe9\xbe\xbf",			// 恢复出厂设置	
	"Restaurer par defaut",
	"Standardwerte laden",
	"Restaurar por defecto",
	"Ripristina imp.",
	"\xbe\xaf\xc3\xb2\xd8\xbe\xaf\xc4",
	"Restaurar padrao",
	"Herstel standaard",
	"Varsayilana dondur",
	"\xb6\xe0 \xe8\x8b\xfc",				// 설정 초기화
	"Восстановить настр.",
};

const char MMSG_PRINT_PAUSED[12][30] PROGMEM = {
	"Print paused",
	"\xca\xf3\xf1\xf2",			// 打印暂停	
	"Imprimer mis en pause",
	"Druck pausiert",
	"Pausar impresion",
	"Stampa sospesa",
	"Print paused",
	"Imprimir pausado",
	"Print onderbroken",
	"Baski duraklatildi",
	"\xeb\x9e \xd7\xbd\xe0\xe6",			// 출력 일시정지
	"Печать на паузе",
};

const char MMSG_PRINTING[12][20] PROGMEM = {
	"Printing...",
	"\xca\xf3...",			// 打印	
	"Impression...",
	"Drucken...",
	"Impresion...",
	"Stampa...",
	"Printing...",
	"Impressao...",
	"het drukken ...",
	"Baski...",
	"\xeb\x9e \xe4...",			// 출력 중...
	"Печать...",
};

const char MMSG_WELCOME_SCREEN_1[12][18] PROGMEM = {
	"Welcome",
	"Welcome",			
	"Bienvenue",
	"Willkommen",
	"Bienvenido",
	"Benvenuto",
	"Welcome",				// ウエルカム
	"Bem vinda",
	"Welkom",
	"Hosgeldiniz",
	"\xfd\xc9\xf9\x91다!",			// 환영합니다!
	"желанный",
};

const char MMSG_WELCOME_SCREEN_2[12][29] PROGMEM = {
	"STEP1:LOAD FILAMENT",
	"\x90 1 \xb7 \xe4\xab\x92\x94",			// 第1步 载入料丝	
	"1 Charger le filament",
	"1 FILAMENT LADEN",
	"1 cargar filamento",
	"1 FILAMENTO DI CARICO",
	"STEP1:LOAD FILAMENT",
	"1 Filamento de Carga",
	"1 LAAD FILAMENT",
	"1 YUK FILAMENTI",
	"1 \xff\x88: \xf7\x9c\xa0\xf2 \x9f\x9b",			// 1단계: 필라멘트 로딩	
	"1 НАГРУЗКА FILAMENT",
};

const char MMSG_WELCOME_SCREEN_3[12][34] PROGMEM = {
	"STEP2:INSERT SD CARD",
	"\x90 2 \xb7 \xaa\xabSD\xa8",			// 第2步 插入SD卡	
	"2 INSERT CARTE SD",
	"2 ERKANNT SD-KARTE",
	"2 Insertar tarjeta SD",
	"2 INSERITA SD CARD",
	"STEP2:INSERT SD CARD",
	"2 Inserir cartao SD",
	"2 PLAATS SD-KAART",
	"2 INSERT SD KART",
	"2 \xff\x88: SD\xed\x99 \xb3\xd8",			// 2단계: SD카드 삽입
	"2 Вставьте SD-карту",
};

const char MMSG_WELCOME_SCREEN_4[12][25] PROGMEM = {
	"STEP3:CHOICE FILE",
	"\x90 3 \xb7 \xca\xf3SD\xa8\x8b\x8c",			// 第3步 打印SD卡文件	
	"3 CHOIX FICHIER",
	"3 WAHLDATEI",
	"3 Archivo de eleccion",
	"3 FILE DI SCELTA",
	"STEP3:CHOICE FILE",
	"3 Arquivo de escolha",
	"3 KEUZEBESTAND",
	"3 SECIM DOSYASI",
	"3 ﻿\xff\x88: \xf4\xd7 \xb5\xef",			// 3단계: 파일 선택
	"3 ВЫБОР ФАЙЛА",
};

const char MMSG_WELCOME_CONINUE[12][20] PROGMEM = {
	"Next",
	"\xf4\xf5",			// 继续	
	"Continuer",
	"Fortsetzen",
	"Continuar",
	"Continua",
	"Next",
	"Proximo",
	"Volgende",
	"Sonraki",
	"\x92﻿\xd3",			// 다음
	"следующий",
};

const char MMSG_WELCOME_SKIP[12][20] PROGMEM = {
	"Quit",
	"\xb5\xb6",			// 跳过
	"Quitter",
	"Verlassen",
	"Salir",
	"Smettere",
	"Quit",
	"Sair",
	"Ophouden",
	"cikmak",
	"\xe4\xe6",			// 중지
	"Уволиться",
};

const char MMSG_FILAMENT_CHANGE_INIT_1[12][20] PROGMEM = {
	"Wait for start",
	"\xfc\xfd\xb3\xb4     ",			// 等待开始	
	"Attendez debut",
	"Warte auf den",
	"Espere a que comience",
	"Attendere avvio",
	"\xba\xb3\xb6\xdd\xa6\xb6\xb2\xbc\xbc\xcf\xbd",
	"Aguarde o inicio",
	"Wacht voor start",
	"Baslama bekleniyor",
	"\xbd\xda",			// 시작
	"Дождитесь",
};

const char MMSG_FILAMENT_CHANGE_INIT_2[12][20] PROGMEM = {
	"of the filament",
	"\x92\x94  ",			// 料丝	
	"du filament",
	"Start des",
	"el cambio",
	"del cambio",
	"\xbc\xca\xde\xd7\xb8\xb5\xcf\xc1\xb8\xc0\xde\xbb\xb2",
	"da mudanca",
	"filament te",
	"filamanin",
	"\xf7\x9c\xa0\xf2",			// 필라멘트
	"начала",
};

const char MMSG_FILAMENT_CHANGE_INIT_3[12][21] PROGMEM = {
	"change",
	"\xfe\xff  ",			// 操作	
	"changement",
	"Filamentwechsels",
	"de filamento",
	"di filamento",
	" ",
	"de filamento",
	"verwisselen",
	"degisimi",
	"\xae\x87",			// 변경
	"смены нити",
};

const char MMSG_FILAMENT_CHANGE_UNLOAD_1[12][20] PROGMEM = {
	"Wait for",
	"\xfc\xfd  ",			// 等待	
	"Attendez ",
	"Warte auf",
	"Espere a que",
	"Attendere",
	"\xcc\xa8\xd7\xd2\xdd\xc4\xc7\xb7\xc0\xde\xbc\xc1\xad\xb3",
	"Esperar para",
	"Wacht voor",
	"Bekleniyor",
	"\x93\x8b",			// 대기	
	"Дождитесь",
};

const char MMSG_FILAMENT_CHANGE_UNLOAD_2[12][20] PROGMEM = {
	"filament unload",
	"\x93\xe4\x92\x94     ",				
	"dechargement",
	"Herausnahme",
	"se descargue",
	"l'espulsione",
	"\xbc\xca\xde\xd7\xb8\xb5\xcf\xc1\xb8\xc0\xde\xbb\xb2",
	"descarregar",
	"filament uit",
	"filamanin cikmasi",
	"\xf7\x9c\xa0\xf2 \xe9\xeb",			 // 필라멘트 추출
	"выгрузки",
};

const char MMSG_FILAMENT_CHANGE_UNLOAD_3[12][20] PROGMEM = {
	" ",
	" ",
	"du filament",
	"des Filaments...",
	"el filamento",
	"del filamento",
	" ",
	"filamento",
	"te laden",
	" ",
	"",
	"нити",
};

const char MMSG_FILAMENT_CHANGE_INSERT_1[12][27] PROGMEM = {
	"Insert filament",
	"\xaa\xab\x92\x94       ",			// 插入料丝	
	"Inserez le filament",
	"Filament einlegen",
	"Inserte filamento",
	"Inserisci il",
	"\xcc\xa8\xd7\xd2\xdd\xc4\xa6\xbf\xb3\xc6\xad\xb3\xbc,",
	"Insira filamento e",
	"Laad filament",
	"Filamani yukle",
	"\xf7\x9c\xa0\xf2 \xb3\xd8",			// 필라멘트 삽입
	"Вставьте нить",
};

const char MMSG_FILAMENT_CHANGE_INSERT_2[12][20] PROGMEM = {
	"and press button",
	"\x8d\x8e\x8f\xf4\xf5       ",			// 并按键	
	"et presser le bouton",
	"und Knopf",
	"y presione el boton",
	"filamento e",
	"\xb8\xd8\xaf\xb8\xbd\xd9\xc4\xbf\xde\xaf\xba\xb3\xbc\xcf\xbd",
	"pressione o botao",
	"en druk knop",
	"ve devam icin",
	"\x8a\xa0\x89 \xaa\xf3\xd2 \x90\xa0\xb7\xce",			// 그리고 버튼을 누르세요
	"и нажмите",
};

const char MMSG_FILAMENT_CHANGE_INSERT_3[12][20] PROGMEM = {
	"to continue...",
	" ",				
	"pour continuer...",
	"drucken...",
	"para continuar...",
	"premi per cont",
	" ",
	"para continuar...",
	"om verder...",
	"tusa bas...",
	"\x88\xba",			// 계속
	"кнопку",
};

const char MMSG_FILAMENT_CHANGE_HEAT_1[12][30] PROGMEM = {
	"Press button to",
	"\x8e\x8f\xb3\xb4     ",			// 按键	
	"Presser le bouton...",
	"Knopf drucken um",
	"Presione él boton para",
	"Premi per",
	"Press button to",
	"Pressione o botao",
	"Klik knop om...",
	"Nozulu Isitmak icin",
	"\xaa\xf3\xd2 \x90\xa0\xbd\xa0",			// 버튼을 누르시면
	"Нажмите кнопку,",
};

const char MMSG_FILAMENT_CHANGE_HEAT_2[12][27] PROGMEM = {
	"heat nozzle.",
	"\xc3\xc4\xd3\xd4     ",			// 预热喷嘴	
	"pour chauffer la buse",
	"Duse aufzuheizen.",
	"Calentar la boquilla",
	"riscald ugello.",
	"heat nozzle.",
	"para aquecer o bocal",
	"verw. nozzle.",
	"Butona Bas.",
	"\x8f\xe5 \x83\xc8",				// 노즐 가열	
	"чтобы нагреть",
};

const char MMSG_FILAMENT_CHANGE_HEATING_1[12][31] PROGMEM = {
	"Heating nozzle",
	"\xc3\xc4\xd3\xd4     ",			// 预热喷嘴	
	"Chauffage des buse",
	"Duse heizt auf...",
	"Calentando boquilla",
	"Riscald. ugello",
	"Heating nozzle",
	"Bico de aquecimento",
	"Nozzle verw.",
	"Nozul Isiniyor",
	"\x8f\xe5 \x83\xc8 \xe4",			// 노즐 가열 중	
	"Отопление сопло",
};

const char MMSG_FILAMENT_CHANGE_HEATING_2[12][23] PROGMEM = {
	"Please wait...",
	"\xfc\xfd...    ",			// 等待	
	"Attendez, SVP...",
	"Bitte warten...",
	"Espere por favor",
	"Attendere...",
	"Please wait...",
	"Por favor, espere",
	"Wacht a.u.b.",
	"Lutfen Bekleyin...",
	"\xdb\xbd \x8b\x92\xa0\xb7\xce...",			// 잠시 기다리세요...	
	"Подождите...",
};

const char MMSG_FILAMENT_CHANGE_LOAD_1[12][20] PROGMEM = {
	"Wait for",
	"\xfc\xfd  ",			// 等待	
	"Attendre la charge",
	"Warte auf",
	"Esperar la carga",
	"Attendere",
	"\xcc\xa8\xd7\xd2\xdd\xc4\xbf\xb3\xc3\xdd\xc1\xad\xb3",
	"Aguarde a carga",
	"Wacht voor",
	"Bekleniyor",
	"\x93\x8b \xe4",				// 대기 중
	"Дождитесь",
};

const char MMSG_FILAMENT_CHANGE_LOAD_2[12][27] PROGMEM = {
	"filament load",
	"\xe4\xab\x92\x94     ",			
	"du filament",
	"Laden des",
	"de filamento",
	"il caricamento",
	"\xbc\xca\xde\xd7\xb8\xb5\xcf\xc1\xb8\xc0\xde\xbb\xb2",
	"de filamento",
	"filament te",
	"filamanin yuklenmesi",
	"\xf7\x9c\xa0\xf2 \xb3\xd8",			// 필라멘트 삽입	
	"загрузки нити",
};

const char MMSG_FILAMENT_CHANGE_LOAD_3[12][20] PROGMEM = {
	" ",
	" ",
	" ",
	" ",
	" ",
	"del filamento",
	" ",
	" ",
	"laden",
	" ",
	" ",
	" ",
};

const char MMSG_FILAMENT_CHANGE_PURGE_1[12][20] PROGMEM = {
	"Wait for",
	" ",			
	"Attendez la purge",
	"Warte auf",
	"Esperar la purga",
	"Attendere",
	"Wait for",
	"Aguarde a limpeza",
	"Wacht op",
	"Filament",
	" ",
	"Дождитесь",
};

const char MMSG_FILAMENT_CHANGE_PURGE_2[12][23] PROGMEM = {
	"filament purge",
	"\xfc\xfd\xe4\xab   ",			// 等待载入
	"du filament",
	"Entleeren des",
	"del filamento",
	"lo spurgo",
	"filament purge",
	"do filamento",
	"filamentreiniging",
	"temizligini",
	"\xf7\x9c\xa0\xf2 \xc0\xeb",			// 필라멘트 압출
	"чистки нити",
};

const char MMSG_FILAMENT_CHANGE_PURGE_3[12][20] PROGMEM = {
	" ",
	" ",			
	" ",
	"Filaments",
	" ",
	"del filamento",
	" ",
	" ",
	" ",
	"bekleyin",
	" ",
	" ",
};

const char MMSG_FILAMENT_CHANGE_RESUME_1[12][30] PROGMEM = {
	"Wait for print",
	"\xfc\xfd  ",			// 等待	
	"Attendez que l'impression",
	"Warte auf",
	"Esperando que se reanude",
	"Attendere",
	"\xcc\xdf\xd8\xdd\xc4\xa6\xbb\xb2\xb6\xb2\xbc\xcf\xbd",
	"Aguarde a impressao",
	"Wacht voor print",
	"Baskinin",
	"\xeb\x9e \x93\x8b",				// 출력 대기
	"Подождите, пока",
};

const char MMSG_FILAMENT_CHANGE_RESUME_2[12][20] PROGMEM = {
	"to resume",
	"\xe7\xe8\xca\xf3    ",			// 继续打印	
	"pour reprendre",
	"Fortsetzung des",
	"la impresion",
	"la ripresa",
	"\xbc\xca\xde\xd7\xb8\xb5\xcf\xc1\xb8\xc0\xde\xbb\xb2",
	"ser retomada",
	"om verder",
	"surdurulmesini",
	"\xdd\x84\xf9\x91\x92",				// 재개합니다	
	"печать на",
};

const char MMSG_FILAMENT_CHANGE_RESUME_3[12][20] PROGMEM = {
	" ",
	" ",			
	" ",
	"Druckes...",
	" ",
	"della stampa",
	" ",
	" ",
	"te gaan",
	"bekle",
	" ",
	"резюме",
};

const char MMSG_ZPROBE_TITLE[12][24] PROGMEM = {
	"Adjust Z Offset(mm)",
	"Z\xce\xc0\xc1(mm)",			// 设置Z偏移	
	"Ajuster Z Offset (mm)",
	"Z-Versatz (mm)",
	"Ajuste Z Offset(mm)",
	"Offset Z (mm)",
	"Adjust Z Offset(mm)",
	"Ajustar Z offset(mm)",
	"Passen Z Offset (mm)",
	"Z Ofset (mm) ayarla",
	"Z\xea \xcc\xb8 \xe2\xe0",			// Z축 옵셋 조정	
	"Смещение Z(mm)",
};

const char MMSG_FILAMENT_CHANGE_HEADER_PAUSE[12][30] PROGMEM = {
	"PRINT PAUSED",
	"\xca\xf3\xf1\xf2     ",			// 打印暂停	
	"IMPRIMER PAUSED",
	"DRUCK PAUSIERT",
	"IMPR. PAUSADA",
	"STAMPA IN PAUSA",
	"PRINT PAUSED",
	"IMPRIMIR PAUSADO",
	"AFDRUK GEPAUZEERD",
	"YAZDIR DURDU",
	"\xeb\x9e \xd7\xbd\xe4\xe6",			// 출력 일시중지
	"Печать на паузе",
};

const char MMSG_FILAMENT_CHANGE_OPTION_HEADER[12][21] PROGMEM = {
	"RESUME OPTIONS:",
	"\xf4\xf5\xfe\xff     ",			// 继续操作	
	"OPTIONS DE REPRISE:",
	"FORTS. OPTIONEN:",
	"OPC. REINICIO:",
	"OPZIONI:",
	"RESUME OPTIONS:",
	"OPCOES DE RESUMO:",
	"RESUME OPTIES:",
	"DEVAM SECENEKLERI:",
	"\xcc\xb9 \xd0\xb0:",			// 옵션 원복:	
	"ПАРАМЕТРЫ:",
};

const char MMSG_FILAMENT_CHANGE_OPTION_PURGE[12][31] PROGMEM = {
	"Purge more",
	"\xe4\xab\xe0\xe1\x92\x94",			// 载入更多料丝	
	"Purge plus",
	"Mehr entleeren",
	"purgar mas",
	"Libera di piu",
	"Purge more",
	"Purgar mais",
	"Purge meer",
	"daha tasfiye et",
	"\xe9\x83 \xc0\xeb",			// 추가 압출
	"Очистить больше",
};

const char MMSG_FILAMENT_CHANGE_OPTION_RESUME[12][22] PROGMEM = {
	"Continue",
	"\xf4\xf5",			// 继续	
	"Continuer",
	"Drucke weiter",
	"Seguir",
	"Riprendi stampa",
	"\xcc\xdf\xd8\xdd\xc4\xbb\xb2\xb6\xb2",
	"Retomar impressao",
	"Hervat print",
	"Baskiyi surdur",
	"\x88\xba",			// 계속
	"Продолжить",
};

const char MMSG_FILAMENT_CHANGE_NOZZLE[12][20] PROGMEM = {
	"  Nozzle: ",
	" \xd3\xd4\xc9\xd2:",			// 喷嘴温度
	"  Buse: ",
	"  Duse: ",
	" Boquilla:",
	"  Ugello: ",
	"  Nozzle: ",
	"  Bocal:  ",
	"  Nozzle: ",
	"  Nozul: ",
	"  \x8f\xe5: ",			// 노즐: 
	"Насадка:",
};

const char MMSG_ERR_HOMING_FAILED[12][22] PROGMEM = {
	"Homing failed",
	"\xbb\xbc\xbd\x9f\x9e",			// 回原点失败
	"Erreur de retour",
	"Homing gescheitert",
	"homing fallo",
	"Home fallito",
	"Homing failed",
	"Homing falhou",
	"Homing is mislukt",
	"Homing basarisiz oldu",
	"\x8f\xe5 \xd0\xd1\xec \xbe\xf5",			// 노즐 원위치 실패
	"не удалось",
};

const char MMSG_ERR_PROBING_FAILED[12][21] PROGMEM = {
	"Probing failed",
	"\xb1\xb2\xcf\xd0\x9f\x9e",			// 自动调平失败
	"Erreur",
	"Probing gescheitert",
	"el sondeo fallo",
	"Probing fallito",
	"Probing failed",
	"Sondagem falhou",
	"Testen is mislukt",
	"Basarisiz sondalama",
	"\xd9\x97\x9a\xaa\x8c \xbe\xf5",			// 자동디버깅 실패
	"не удалось",
};

const char MMSG_SD_INSERTED[12][31] PROGMEM = {
	"Card inserted",
	"\xa8\xa9\xaa\xab",			// 卡已插入
	"carte inseree",
	"SD-Karte erkannt",
	"Tarjeta insertada",
	"SD Card inserita",
	"\xb6\xb0\xc4\xde\xb6\xde\xbf\xb3\xc6\xad\xb3\xbb\xda\xcf\xbc\xc0",
	"Cartao inserido",
	"Kaart ingestoken",
	"SD Yerlesti.",
	"SD\xed\x99 \xb3\xd8\x98.",			// SD카드 삽입됨.
	"Карта вставлена",
};

const char MMSG_SD_REMOVED[12][31] PROGMEM = {
	"Card removed",
	"\xa8\xa9\xac\xad",			// 卡已拔出
	"carte retiree",
	"SD-Karte entfernt",
	"Tarjeta extraida",
	"SD Card rimossa",
	"\xb6\xb0\xc4\xde\xb6\xde\xb1\xd8\xcf\xbe\xdd",
	"Cartao removido",
	"Kaart verwijderd",
	"SD cikarildi.",
	"SD\xed\x99 \xe1\x85\x98",			// SD카드 제거됨.
	"Карта извлечена",
};

const char MMSG_MOVE_X[12][25] PROGMEM = {
	"Move X",
	"\xc1\xb2 X",			// 移动X
	"Deplacer X",
	"Verschiebe X",
	"Mover X",
	"Muovi X",
	"X\xbc\xde\xb8\x20\xb2\xc4\xde\xb3",
	"Mover X",
	"Verplaats X",
	"X",
	"X\xea \xd4\x97",			// X축 이동
	"Движение по X",
};

const char MMSG_MOVE_Y[12][25] PROGMEM = {
	"Move Y",
	"\xc1\xb2 Y",			// 移动Y
	"Deplacer Y",
	"Verschiebe Y",
	"Mover Y",
	"Muovi Y",
	"Y\xbc\xde\xb8\x20\xb2\xc4\xde\xb3",
	"Mover Y",
	"Verplaats Y",
	"Y",
	"Y\xea \xd4\x97",			// Y축 이동
	"Движение по Y",
};

const char MMSG_MOVE_Z[12][25] PROGMEM = {
	"Move Z",
	"\xc1\xb2 Z",			// 移动Z
	"Deplacer Z",
	"Verschiebe Z",
	"Mover Z",
	"Muovi Z",
	"Z\xbc\xde\xb8\x20\xb2\xc4\xde\xb3",
	"Mover Z",
	"Verplaats Z",
	"Z",
	"Z\xea \xd4\x97",			// Z축 이동
	"Движение по Z",
};

const char MMSG_MOVE_E[12][20] PROGMEM = {
	"Extruder",
	"\xcc\xad\xba",			// 挤出机
	"Extrudeur",
	"Extruder",
	"Extrusor",
	"Estrusore",
	"\xb4\xb8\xbd\xc4\xd9\xb0\xc0\xde\xb0",
	"Mover Extrusor",
	"Extruder",
	"Ekstruder",
	"\xd5\xbb\xf2\xa0\x94",			// 익스트루더
	"Экструдер",
};

const char MMSG_MOVE_01MM[12][26] PROGMEM = {
	"Move 0.1mm",
	"\xc1\xb2 0.1mm",			// 移动0.1mm
	"Deplacer 0.1mm",
	"0.1mm",
	"Mover 0.1mm",
	"Muovi di 0.1mm",
	"0.1mm \xb2\xc4\xde\xb3",
	"Mover 0.1mm",
	"Verplaats 0.1mm",
	"0.1mm",
	"0.1mm \xd4\x97",			// 0.1mm 이동
	"Движение 0.1мм",
};

const char MMSG_MOVE_1MM[12][24] PROGMEM = {
	"Move 1mm",
	"\xc1\xb2 1mm",			// 移动1mm
	"Deplacer 1mm",
	"1mm",
	"Mover 1mm",
	"Muovi di   1mm",
	"  1mm \xb2\xc4\xde\xb3",
	"Mover 1mm",
	"Verplaats 1mm",
	"1mm",
	"1mm \xd4\x97",			// 1mm 이동
	"Движение 1мм",
};

const char MMSG_MOVE_10MM[12][25] PROGMEM = {
	"Move 10mm",
	"\xc1\xb2 10mm",			// 移动10mm
	"Deplacer 10 mm",
	"10mm",
	"Mover 10mm",
	"Muovi di  10mm",
	" 10mm \xb2\xc4\xde\xb3",
	"Mover 10mm",
	"Verplaats 10mm",
	"10mm",
	"10mm \xd4\x97",			// 10mm 이동
	"Движение 10мм",
};

const char MMSG_TUNE[12][20] PROGMEM = {
	"Tune",
	"\xcf\xf0",			// 调整
	"Regler",
	"Justierung",
	"Ajustar",
	"Regola",
	"\xc1\xae\xb3\xbe\xb2",
	"Afinar",
	"Afstellen",
	"Ayar",
	"\xe2\xe0",			// 조정
	"Настроить",
};

const char MMSG_PAUSE_PRINT[12][25] PROGMEM = {
	"Pause print",
	"\xf1\xf2\xca\xf3",			// 暂停打印
	"Pause impression",
	"SD-Druck Pause",
	"Pausar impresion",
	"Pausa",
	"\xb2\xc1\xbc\xde\xc3\xb2\xbc",
	"Pausar impressao",
	"Print pauzeren",
	"Duraklat",
	"\xeb\x9e \xd7\xbd\xe4\xe6",			// 출력 일시중지
	"Пауза печати",
};

const char MMSG_RESUME_PRINT[12][35] PROGMEM = {
	"Resume print",
	"\xf4\xf5\xca\xf3",			// 继续打印
	"Reprendre impression",
	"SD-Druck Fortsetzung",
	"Retomar impresion",
	"Riprendi stampa",
	"\xcc\xdf\xd8\xdd\xc4\xbb\xb2\xb6\xb2",
	"Retomar impressao",
	"Print hervatten",
	"Surdur",
	"\xeb\x9e \xdd\x84",			// 출력 재개
	"Продолжить печать",
};

const char MMSG_STOP_PRINT[12][35] PROGMEM = {
	"Stop print",
	"\xf2\xf6\xca\xf3",			// 停止打印
	"Arret impression",
	"SD-Druck Abbruch",
	"Detener impresion",
	"Arresta stampa",
	"\xcc\xdf\xd8\xdd\xc4\xc3\xb2\xbc",
	"Parar impressao",
	"Print stoppen",
	"Durdur",
	"\xeb\x9e \xe4\xe6",			// 출력 중지
	"Остановить печать",
};

const char MMSG_NO_CARD[12][22] PROGMEM = {
	"No SD card",
	"\xf9\xa8",			// 无卡
	"Aucune carte SD",
	"Keine SD-Karte",
	"No hay tarjeta SD",
	"SD non presente",
	"SD\xb6\xb0\xc4\xde\xb6\xde\xb1\xd8\xcf\xbe\xdd",
	"Sem cartao SD",
	"Geen SD kaart",
	"SD Kart Yok",
	"SD\xed\x99\x83 \xc5\xbc\x91\x92.",			// SD카드가 없습니다.
	"Нет SD карты",
};

const char MMSG_SPEED[12][18] PROGMEM = {
	"Speed",
	"\xd1\xd2",			// 速度
	"La vitesse",
	"Geschw.",
	"Velocidad",
	"Velocita",
	"\xbf\xb8\xc4\xde",
	"Velocidade",
	"Snelheid",
	"Hiz",
	"\xba\x96",			// 속도
	"Скорость",
};

const char MMSG_NOZZLE[12][12] PROGMEM = {
	"Nozzle",
	"\xd3\xd4",			// 喷嘴
	"Buse",
	"Duse",
	"Boquilla",
	"Ugello",
	"\xc9\xbd\xde\xd9",
	"Bico",
	"Nozzle",
	"Nozul",
	"\x8f\xe5",			// 노즐
	"Сопло",
};

const char MMSG_BED[12][12] PROGMEM = {
	"Bed",
	"\xc4\xc7",			// 热床
	"Lit",
	"Bett",
	"Plataforma",
	"Piatto",
	"\xcd\xde\xaf\xc4\xde",
	"Base",
	"Bed",
	"Tabla",
	"\xac\x99",			// 베드
	"Стол",
};

const char MMSG_FAN_SPEED[12][18] PROGMEM = {
	"Fan speed",
	"\xd5\xd6\xd1\xd2",			// 风扇速度
	"Vitesse ventil",
	"Lufter",
	"Ventilador",
	"Velocita ventola",
	"\xcc\xa7\xdd\xbf\xb8\xc4\xde",
	"Vel. ventoinha",
	"Fan snelheid",
	"Fan Hizi",
	"\xf6 \xba\x96",			// 팬 속도
	"Кулер",
};

const char MMSG_FLOW[12][12] PROGMEM = {
	"Flow",
	"\xcc\xad\xd1\xd2",			// 挤出速度
	"Couler",
	"Flussrate",
	"Flujo",
	"Flusso",
	"\xc4\xbc\xad\xc2\xd8\xae\xb3",
	"Fluxo",
	"Flow",
	"Akis",
	"\xc0\xeb \xba\x96",			// 압출 속도
	"Поток",
};

const char MMSG_POWER_LOSS_RECOVERY[12][30] PROGMEM = {
	"Power Loss Recovery",
	"\xe7\xe8\xca\xf3",			// 恢复打印
	"Recup. des pertes",
	"Wiederherstellung",
	"Recuperacion energia",
	"Recupero",
	"Power Loss Recovery",
	"Retomar a recuperacao",
	"Herstel stroomverlies",
	"Guc Kaybı Kurtarma",
	"\xb0\xd0",			// 복원
	"восстановление",
};

const char MMSG_SAVED_OFF[12][27] PROGMEM = {
	"Save Printing and Off",
	"\xe5\xe6\xb5\xba    ",			// 保存关机
	"Enregistrer et OFF",
	"Speichern und weg",
	"Guardar y apagar",
	"Salva stampa e Off",
	"Save Printing and Off",
	"Salvar e Desativar",
	"Opslaan en Off",
	"Kaydet ve Kapat",
	"\xeb\x9e \xde\xdc \xfe \x8d\xe7",			// 출력 저장 후 꺼짐
	"Сохранить и Off",
};

const char MMSG_SAVED_OFF_1[12][33] PROGMEM = {
	"Wait for printing",
	"\xfc\xfd\xca\xf3\xf2\xf6\x91",			// 等待打印停止后		
	"Attendez l'arret",
	"Warten fur Druckstopp",
	"Espere a que se",
	"Attendere fermata",
	"Wait for printing",
	"Aguarde a parada da",
	"Wacht tot het afdru-",
	"Daha sonra, durdurma",
	"\xeb\x9e \xcd\xa0 \x93\x8b",			// 출력 완료 대기
	"Дождитесь печати",
};

const char MMSG_SAVED_OFF_2[12][22] PROGMEM = {
	"stop, then turn off",
	"\xb5\xb6\xb9\xcb",			// 关闭电源		
	"de l'impression, puis",
	"dann Ausschalten",
	"detenga la impresion,",
	"la stampa,",
	"stop, then turn off",
	"impressao e desligue",
	"kken te stoppen,",
	"baski bekleyin",
	"\xe4\xe6 \xfe \x8d\xe7",			// 중지 후 꺼짐	
	"стоп, затем",
};

const char MMSG_SAVED_OFF_3[12][35] PROGMEM = {
	"the power",
	" ",				
	"coupez l'alimentation",
	" ",
	"luego apague",
	"quindi spegnere",
	"the power",
	"a energia",
	"zet de stroom uit",
	"gucu kapatin",
	"\xdf\xd0",			// 전원
	"выключите питание",
};

const char MMSG_MOVING[12][21] PROGMEM = {
	"Moving...",
	"\xc1\xb2...",		// 移动
	"Deplacement...",
	"In Bewegung...",
	"Moviendo...",
	"In movimento...",
	"\xb2\xc4\xde\xb3\xc1\xad\xb3",                                     // ｲﾄﾞｳﾁｭｳ (Moving...)
	"Mover-se ...",
	"Verplaatsen...",
	"Konumlaniyor...",
	"\xd4\x97...",			// 이동 ...
	"Движемся...",
};

const char MMSG_PRE_PAGE[12][22] PROGMEM = {
	"Previous",
	"\xde\xfa\xfb",		// 前一页
	"Precedent",
	"Bisherige",
	"Anterior",
	"Precedente",
	"Previous",
	"Anterior",
	"voorgaand",
	"Onceki",
	"Previous",			//
	"Назад",
};

const char MMSG_NEXT_PAGE[12][22] PROGMEM = {
	"Next",
	"\x91\xfa\xfb",			// 后一页
	"Prochain",
	"Nachster",
	"Proximo",
	"Prossimo",
	"Next",
	"Proximo",
	"volgende",
	"Sonraki",
	"Next",		
	"следующий",
};

const char MMSG_DO_PRINT[12][16] PROGMEM = {
	"Print",
	"\xca\xf3",			// 打印	
	"Impression",
	"Drucken",
	"Impresion",
	"Stampa",
	"Print",
	"Impressao",
	"het drukken",
	"Baski",
	"\xeb\x9e \xe4",			// 출력 중...
	"печать",
};

const char MMSG_RESTORE_PRINT[12][24] PROGMEM = {
	"Resume printing...",
	"\xe7\xe8\xca\xf3...",			// 恢复打印	
	"Reprise...",
	"Druck fortsetzen...",
	"Retomar impresion",
	"Riprendi stampa...",
	"Resume printing...",
	"Curriculo...",
	"Doorgaan met...",
	"Surdurme ...",
	"\xdd\x84\...",				
	"Резюмируя ...",
};

const char MMSG_OCTOPRINT_OPEN[]  PROGMEM = {
	"SparkOne Online"
};

const char MMSG_OCTOPRINT_CLOSE[]  PROGMEM = {
	"SparkOne Offline"
};

const char MMSG_HOST_MENU[12][23] PROGMEM = {
	"Host Mode",
	"\xae\xba\xd8\xd9\xbe\xbf",			// 主机控制设置
	"Mode hote",
	"Host-Modus",
	"Modo Host",
	"Modalita host",
	"Host Mode",
	"Modo Host",
	"Host-modus",
	"Ana Bilgisayar Modu",
	"Host Mode",
	"Режим хоста",
};

const char MMSG_HOST_WIIBUILDER[]  PROGMEM = {
	"Wiibuilder"
};

const char MMSG_HOST_SPARK[]  PROGMEM = {
	"SparkOne"
};

const char MMSG_HEATING[12][20] PROGMEM = {
	"Heating...",
	"Heating...",
	"Heating...",
	"Heating...",
	"Heating...",
	"Heating...",
	"Heating...",
	"Heating...",
	"Heating...",
	"Heating...",
	"Heating...",
	"Heating...",
};

const char MMSG_COOLING[12][26] PROGMEM = {
	"Cooling...",
	"Cooling...",
	"Cooling...",
	"Cooling...",
	"Cooling...",
	"Cooling...",
	"Cooling...",
	"Cooling...",
	"Cooling...",
	"Cooling...",
	"Cooling...",
	"Cooling...",
};

const char MMSG_INFO_HEIGHT[12][18] PROGMEM = {
	"LayerHeight:",
	"LayerHeight:",
	"Precision:",
	"LayerHeight:",
	"LayerHeight:",
	"LayerHeight:",
	"LayerHeight:",
	"LayerHeight:",
	"LayerHeight:",
	"LayerHeight:",
	"LayerHeight:",
	"LayerHeight:",
};

const char MMSG_INFO_DENSITY[12][14] PROGMEM = {
	"Density:",
	"Density:",
	"Densite:",
	"Density:",
	"Density:",
	"Density:",
	"Density:",
	"Density:",
	"Density:",
	"Density:",
	"Density:",
	"Density:",
};

const char MMSG_INFO_FILAMENT[12][15] PROGMEM = {
	"Filament:",
	"Filament:",
	"Filament:",
	"Filament:",
	"Filament:",
	"Filament:",
	"Filament:",
	"Filament:",
	"Filament:",
	"Filament:",
	"Filament:",
	"Filament:",
};

const char MMSG_INFO_USAGE[12][12] PROGMEM = {
	"Usage:",
	"Usage:",
	"Usage:",
	"Usage:",
	"Usage:",
	"Usage:",
	"Usage:",
	"Usage:",
	"Usage:",
	"Usage:",
	"Usage:",
	"Usage:",
};

const char MMSG_INFO_TEMP[12][20] PROGMEM = {
	"Temperature:",
	"Temperature:",
	"Temperature:",
	"Temperature:",
	"Temperature:",
	"Temperature:",
	"Temperature:",
	"Temperature:",
	"Temperature:",
	"Temperature:",
	"Temperature:",
	"Temperature:",
};
	
const char MMSG_INFO_TIME[12][20] PROGMEM = {
	"PrintTime:",
	"PrintTime:",
	"Temps d'impre:",
	"PrintTime:",
	"PrintTime:",
	"PrintTime:",
	"PrintTime:",
	"PrintTime:",
	"PrintTime:",
	"PrintTime:",
	"PrintTime:",
	"PrintTime:",
};


#endif // 
