#include "processthread.h"



ProcessThread::ProcessThread(Ui::MainWindow *Ui, QMutex *lock)://, QCustomPlot *plot1, QCustomPlot *plot2, QTextBrowser *textbrowser):
     ui(Ui), data_lock(lock)
{
    bigNum();
}

void ProcessThread::run()
{

    QByteArray bTempDataRev = mData;
    QByteArray bCmd = bTempDataRev;
    bCmd.chop(13);

    if(bCmd == "SPID")
    {
        bTempDataRev.chop(2);
        bTempDataRev = bTempDataRev.right(8).toHex();
        dataPIDProcess(bTempDataRev, &fKp, &fKi, &fKd);
        emit PIDBrowser(QString::number(fKp), QString::number(fKi), QString::number(fKd), bCmd);
        qDebug() << "PID Pramas: " << QString::number(fKp) << " " << QString::number(fKi) << " " << QString::number(fKd) << "\n" ;
        bCmd.clear();
    }
    else if(bCmd == "CTUN")
    {
        QString text = "CTUN cmd completed \n";
        emit TUNBrowser(text);
    }
    else if(bCmd == "GPID")
    {
        bTempDataRev.chop(2);
        bTempDataRev = bTempDataRev.right(8).toHex().toUpper();

        long bCount;
        long bPosition;
        bool ok;

        int iCount1 = static_cast<quint8>(bTempDataRev[4]);
        int iCount2 = static_cast<quint8>(bTempDataRev[5]);
        int iCount3 = static_cast<quint8>(bTempDataRev[6]);
        int iCount4 = static_cast<quint8>(bTempDataRev[7]);
        int iPos1 = static_cast<quint8>(bTempDataRev[12]);
        int iPos2 = static_cast<quint8>(bTempDataRev[13]);
        int iPos3 = static_cast<quint8>(bTempDataRev[14]);
        int iPos4 = static_cast<quint8>(bTempDataRev[15]);

        Ascii2Int( &iCount1,&iCount2, &iCount3, &iCount4);
        Ascii2Int( &iPos1,&iPos2, &iPos3, &iPos4);

        bCount= (double)(iCount1*4096 +iCount2*256 + iCount3*16 + iCount4);
        bPosition= (double)(iPos1*4096 +iPos2*256 + iPos3*16 + iPos4);

        a[k] = bCount;
        b[k] =bPosition;
        emit updategraph(a[k], b[k]);
       /*if( (bPosition != 0) && (bPosition < 180) && (bCount != 0) && (bCount < 200))
          {*/
              /* a[k] = bCount;
               b[k] =bPosition;
               ui -> pidPlot -> graph(1) ->setData(a, b);
               ui->pidPlot->rescaleAxes();
               ui->pidPlot->replot();
               ui-> pidPlot -> update();
               qDebug() << "Positon: " <<bPosition  << " " << "Count: " <<bCount << "\n" ;

               // if(k>2)
                //{
                    //if(b[k] > posMax)
                    //{
                   //posMax = b[k];
                   // }
               // }
                //posxl = b[k];
              k++;*/

           /* }
        else
        {
            if(k>2)
            {
                if(b[k-1] < b[k-2])
                {
                    a[k] = a[k - 1] + 1;
                    b[k] = b[k -1] -1;
                }
                else if (b[k -1] == b[k-2])
                {
                    a[k] = a[k - 1] + 1;
                    b[k] = b[k -1];
                }
                else
                {
                    a[k] = a[k - 1] + 1;
                    b[k] = b[k -1] + 1;
                }
                ui -> pidPlot -> graph(1) ->setData(a, b);
                ui->pidPlot->rescaleAxes();
                ui->pidPlot->replot();
                ui-> pidPlot -> update();
                k++;
                //posxl = b[k];
            }
        }
    }
    else if(bCmd == "GRMS")
    {

    }
    else
    {

    }*/
    }
    //QScrollBar *sb = ui->textBrowser->verticalScrollBar();
    //sb->setValue(sb->maximum());
}

void ProcessThread::dataPIDProcess(QByteArray &bdata, float *fKp, float *fKi, float *fKd)
{
    QByteArray bKRev;
    bKRev.resize(2);
    bKRev.clear();


    bKRev.append(bdata[0]);
    bKRev.append(bdata[1]);
    bool bStatus;
    uint iKpRev1 = QString(bKRev).toUInt(&bStatus,16);
    bKRev.clear();

    bKRev.append(bdata[2]);
    bKRev.append(bdata[3]);
    bStatus = false;
    uint iKpRev2 = QString(bKRev).toUInt(&bStatus,16);
    bKRev.clear();

    bKRev.append(bdata[4]);
    bKRev.append(bdata[5]);
    bStatus = false;
    uint iKiRev1 = QString(bKRev).toUInt(&bStatus,16);
    bKRev.clear();

    bKRev.append(bdata[6]);
    bKRev.append(bdata[7]);
    bStatus = false;
    uint iKiRev2 = QString(bKRev).toUInt(&bStatus,16);
    bKRev.clear();

    bKRev.append(bdata[8]);
    bKRev.append(bdata[9]);
    bStatus = false;
    uint iKdRev1 = QString(bKRev).toUInt(&bStatus,16);
    bKRev.clear();

    bKRev.append(bdata[10]);
    bKRev.append(bdata[11]);
    bStatus = false;
    uint iKdRev2 = QString(bKRev).toUInt(&bStatus,16);
    bKRev.clear();

    *fKp = (float)iKpRev1 + (float)iKpRev2/100 ;
    *fKi = (float)iKiRev1 + (float)iKiRev2/100;
    *fKd = (float)iKdRev1 + (float)iKdRev2/100;
}

void ProcessThread::Ascii2Int(int *a, int *b, int *c, int *d)
{
    AsciiConvert(a);
    AsciiConvert(b);
    AsciiConvert(c);
    AsciiConvert(d);
}

void ProcessThread::AsciiConvert(int *a)
{
    switch(*a)
    {
    case 48:
        *a = 0;
        break;
    case 49:
        *a = 1;
        break;
    case 50:
        *a = 2;
        break;
    case 51:
        *a = 3;
        break;
    case 52:
        *a = 4;
        break;
    case 53:
        *a = 5;
        break;
    case 54:
        *a = 6;
        break;
    case 55:
        *a = 7;
        break;
    case 56:
        *a = 8;
        break;
    case 57:
        *a = 9;
        break;
    case 97:
        *a = 10;
        break;
    case 98:
        *a = 11;
        break;
    case 99:
        *a = 12;
        break;
    case 100:
        *a = 13;
        break;
    case 101:
        *a = 14;
        break;
    case 102:
        *a = 15;
        break;
    case 65:
        *a = 10;
        break;
    case 66:
        *a = 11;
        break;
    case 67:
        *a = 12;
        break;
    case 68:
        *a = 13;
        break;
    case 69:
        *a = 14;
        break;
    case 70:
        *a = 15;
        break;
    default:
        break;
    }
}

void ProcessThread::updatePlot()
{
    a.fill(0);
    b.fill(0);
    k = 0;
    ui -> pidPlot -> graph(0) -> setData(c,d);
    ui -> pidPlot -> graph(1) -> setData(a,b);
    ui-> pidPlot->rescaleAxes();
    ui-> pidPlot->replot();
    ui-> pidPlot -> update();
}

void ProcessThread::bigNum()
{
    a.resize(201);
    b.resize(201);
    e.resize(1001);
    f.resize(1001);
}
