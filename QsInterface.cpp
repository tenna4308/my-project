
#include "stdafx.h"
#include "QsComm.h"
#include "QueueSch.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


/////////////////////////////////////////////////////////////
// ������MT4�ӿڵĺ���ʵ��
/////////////////////////////////////////////////////////////
//+------------------------------------------------------------------+
//| DLL����ӿ�                                                      |
//+------------------------------------------------------------------+
MT4_EXPFUNC double _stdcall test1(TData *Rates, int MaximumRecords, int Iteration)
{
    return (Rates[MaximumRecords - Iteration - 1].close);
}
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
//+------------------------------------------------------------------+
//| DLL���Խӿ�                                                      |
//+------------------------------------------------------------------+
//����debug��Ϣ���ε�ַ�ͳ��ȣ�����debug��Ϣ������������д��arr��ַ��
MT4_EXPFUNC UINT _stdcall QsGetStat(int *arr,const int arraysize)
{
    GREATER_RETURN_VALUE(arraysize,QS_STATIS_DEBUG_NUM,QS_FAIL);

    CQueueSch::GetQueueSch()->GetQsStat(&arr[0], arraysize);

    return QS_SUCC;
}
MT4_EXPFUNC UINT _stdcall QsGetDebug(double *arr,const int arraysize)
{
    GREATER_RETURN_VALUE(arraysize,QS_STATIS_DEBUG_NUM,QS_FAIL);

    CQueueSch::GetQueueSch()->GetQsDebug(&arr[0], arraysize);

    return QS_SUCC;
}
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
//+------------------------------------------------------------------+
//| DLL��������                                                      |
//+------------------------------------------------------------------+
/////////////////////////////////////////////////////////////
// �ӿں궨��
/////////////////////////////////////////////////////////////
#define INIT_OUT_MA7_PERIOD  0
#define INIT_OUT_MA14_PERIOD 1
#define INIT_OUT_MA28_PERIOD 2
#define INIT_OUT_MA200_PERIOD 3
#define INIT_OUT_MACD_FAST_PERIOD   4
#define INIT_OUT_MACD_SLOW_PERIOD   5
#define INIT_OUT_MACD_SIGNAL_PERIOD 6
#define INIT_OUT_ADX14_PERIOD 7
//��ʼ��,��ʼ��֤��һ��׼�ֱ�֤��
MT4_EXPFUNC UINT _stdcall QsInit(double dSpread, double dOriMargin, double dMarginRequired, double *patDataInfo)
{
    CQueueSch::GetQueueSch()->DefaultInit(dSpread, dOriMargin, dMarginRequired, patDataInfo);
    CQueueSch::GetQueueSch()->GetMaCfg(patDataInfo + INIT_OUT_MA7_PERIOD);
    CQueueSch::GetQueueSch()->GetMacdCfg(patDataInfo + INIT_OUT_MACD_FAST_PERIOD);
    CQueueSch::GetQueueSch()->GetAdxCfg(patDataInfo + INIT_OUT_ADX14_PERIOD);
    return QS_SUCC;
}

/////////////////////////////////////////////////////////////
// �ӿں궨��
/////////////////////////////////////////////////////////////
#define INIT_IN_MA7_PERIOD       0
#define INIT_IN_H1MA7_LASTLAST   1
#define INIT_IN_H1MA7_LAST       2
#define INIT_IN_H1MA7_CURRENT    3
#define INIT_IN_MA14_PERIOD      4
#define INIT_IN_H1MA14_LASTLAST  5
#define INIT_IN_H1MA14_LAST      6
#define INIT_IN_H1MA14_CURRENT   7
#define INIT_IN_MA28_PERIOD      8
#define INIT_IN_H1MA28_LASTLAST  9
#define INIT_IN_H1MA28_LAST      10
#define INIT_IN_H1MA28_CURRENT   11
#define INIT_IN_MA200_PERIOD     12
#define INIT_IN_H1MA200_LASTLAST 13
#define INIT_IN_H1MA200_LAST     14
#define INIT_IN_H1MA200_CURRENT  15
#define INIT_IN_M1MA7_LAST       16
#define INIT_IN_M1MA7_CURRENT    17
#define INIT_IN_M1MA14_LAST      18
#define INIT_IN_M1MA14_CURRENT   19
#define INIT_IN_M1MA28_LAST      20
#define INIT_IN_M1MA28_CURRENT   21
#define INIT_IN_M1MA200_LAST     22
#define INIT_IN_M1MA200_CURRENT  23

#define INIT_IN_MACD_MAIN_LASTLAST    24  //MACD ��Ҫ����б��ҲҪ������ֵ���죬��Ҫ���k��ֵ
#define INIT_IN_MACD_MAIN_LAST        25
#define INIT_IN_MACD_MAIN_CUR         26
#define INIT_IN_MACD_SIGNAL_LASTLAST  27  //MACD ��Ҫ����б��ҲҪ������ֵ���죬��Ҫ���k��ֵ
#define INIT_IN_MACD_SIGNAL_LAST      28
#define INIT_IN_MACD_SIGNAL_CUR       29

#define INIT_IN_ADX14_MAIN_LAST       30
#define INIT_IN_ADX14_BUY_LAST        31
#define INIT_IN_ADX14_SELL_LAST       32
#define INIT_IN_ADX14_MAIN_CUR        33
#define INIT_IN_ADX14_BUY_CUR         34
#define INIT_IN_ADX14_SELL_CUR        35

#define INIT_IN_RSI7_LASTVALUE        40
#define INIT_IN_RSI14_LASTVALUE       41
#define INIT_IN_RSI28_LASTVALUE       42
#define INIT_IN_RSI7_CURVALUE         43
#define INIT_IN_RSI14_CURVALUE        44
#define INIT_IN_RSI28_CURVALUE        45

#define INIT_IN_LASTLASTBAND_UP       50
#define INIT_IN_LASTLASTBAND_MIDDLE   51
#define INIT_IN_LASTLASTBAND_DOWN     52
#define INIT_IN_LASTBAND_UP           53
#define INIT_IN_LASTBAND_MIDDLE       54
#define INIT_IN_LASTBAND_DOWN         55
#define INIT_IN_CURBAND_UP            56
#define INIT_IN_CURBAND_MIDDLE        57
#define INIT_IN_CURBAND_DOWN          58

#define INIT_IN_DATA_ADDR             60 //��������Ϣ��6��

#define INIT_IN_CUR_YEAR              70
#define INIT_IN_CUR_MONTH             71
#define INIT_IN_CUR_DAY               72
#define INIT_IN_CUR_HOUR              73
#define INIT_IN_CUR_MINUTE            74
#define INIT_IN_CUR_DAYOFWEEK         75

#define INIT_IN_CUR_GBPUSD_MA1        80
#define INIT_IN_CUR_EURUSD_MA1        81
#define INIT_IN_CUR_USDCHF_MA1        82
#define INIT_IN_CUR_USDJPY_MA1        83
#define INIT_IN_CUR_AUDUSD_MA1        84
#define INIT_IN_CUR_USDCAD_MA1        85
#define INIT_IN_CUR_EURJPY_MA1        86
#define INIT_IN_CUR_EURAUD_MA1        87
#define INIT_IN_CUR_EURCHF_MA1        88
#define INIT_IN_CUR_EURGBP_MA1        89
#define INIT_IN_CUR_GBPJPY_MA1        90
#define INIT_IN_CUR_GBPAUD_MA1        91
#define INIT_IN_CUR_GBPCHF_MA1        92

#define INIT_IN_ORDER_NUM             95 //����32��������

//��Ҫ�������� ֵ������׼�ֱ�֤�𡢷��ش���������arr�����ma��Ϣ���̡��С�����������Ҫ����Ķ����ڲ������ţ�
//QsPeriodInit 7.00000000 1.57522548 1.57521911 14.00000000 1.57425279 1.57437909 28.00000000 1.57254713 1.57273009 200.00000000 1.55975418 1.55990787
MT4_EXPFUNC UINT _stdcall QsPeriodInit(double dPoint,double dSpread, double dAccountEquity, double dMarginreQuired,double *arr,const int arraysize)
{
    USHORT usOrderIdx;
    UINT uiOrderNum = 0;

    //���ﷵ�ش�����waiting��������0����Чֵ��-1����Чֵ��
    EQ_RETURN_VALUE(arr, NULL,-1);
    LESS_RETURN_VALUE(arraysize, 128, -1);
    LESS_RETURN_VALUE(dPoint, 0.00001, -1);

    CQueueSch::GetQueueSch()->SetCurrentPoint(dPoint, dSpread, arr + INIT_IN_CUR_YEAR);
    CQueueSch::GetQueueSch()->InitCurMaxOpen(dAccountEquity,dMarginreQuired);

    //��ȡ���ݵ���Ϣ
    CQueueSch::GetQueueSch()->SetDataInfo(arr + INIT_IN_DATA_ADDR);

    //��ȡMACD��Ϣ 7����Ϣ, ���������ú�4�����ݣ��м�����������Ҫʱ�����á�
    CQueueSch::GetQueueSch()->SetMacdInfo(arr + INIT_IN_MACD_MAIN_LASTLAST);

    //rsi
    CQueueSch::GetQueueSch()->SetRsiInfo(arr + INIT_IN_RSI7_LASTVALUE);

    //����MA������Ϣ -- MA��������ע���ڵ㣻Ĭ�ϣ�7��14��28;������һ��ֵ����ǰMA��ֵ
    CQueueSch::GetQueueSch()->SetH1MaInfo(arr + INIT_IN_MA7_PERIOD); 
    CQueueSch::GetQueueSch()->SetH1MaInfo(arr + INIT_IN_MA14_PERIOD); 
    CQueueSch::GetQueueSch()->SetH1MaInfo(arr + INIT_IN_MA28_PERIOD); 
    CQueueSch::GetQueueSch()->SetH1MaInfo(arr + INIT_IN_MA200_PERIOD); 
    CQueueSch::GetQueueSch()->SetM1MaInfo(arr + INIT_IN_M1MA7_LAST);
    //����band��Ϣ
    CQueueSch::GetQueueSch()->SetBandInfo(arr + INIT_IN_LASTLASTBAND_UP);
    
    //����adx��Ϣ
    CQueueSch::GetQueueSch()->SetAdxInfo(arr + INIT_IN_ADX14_MAIN_LAST);

    //���ݷ��� -- �����Ƿ����¿��ֶ�����֮ǰ�ж��Ƿ�ﵽֹӯ��ֹ�𡢾��Ʋ���ƽ�� -- ���ܵ���waitlink��timerlink�仯
    CQueueSch::GetQueueSch()->QsResult(&usOrderIdx, arr + INIT_IN_ORDER_NUM);

    //��ʱɨ�� -- �жϳ�ʱ  -- ���ܵ���waitlink��timerlink�仯
    CQueueSch::GetQueueSch()->TimerBaseScan();

    //���ش������� -- ��waitlink�������д���
    uiOrderNum = CQueueSch::GetQueueSch()->GetWaitingOrder(arr, arraysize);
#ifdef DBG_OUTPUT
    //����ƽ��ʱ��stat debug��Ϣ 255������ʹ�á�
    if (uiOrderNum == 0)
    {
        //CQueueSch::GetQueueSch()->SaveDebugInfo(0,0);
    }
#endif
    //ָ��ʱ�����
    //����˳�� ���µ����ٺ���׷�١��ٺ�����ƽ������ȫƽ����ֹӯ��ֹ����ɡ�
    /*
    CQueueSch::GetQueueSch()->SaveResultByTime("200107241400");
    CQueueSch::GetQueueSch()->SaveResultByTime("200107250730");
    CQueueSch::GetQueueSch()->SaveResultByTime("200101121017");
    CQueueSch::GetQueueSch()->SaveResultByTime("200101160411");
    CQueueSch::GetQueueSch()->SaveResultByTime("200101220439");
    CQueueSch::GetQueueSch()->SaveResultByTime("200102231300");
    CQueueSch::GetQueueSch()->SaveResultByTime("200103020333");
    CQueueSch::GetQueueSch()->SaveResultByTime("200103130309");
    CQueueSch::GetQueueSch()->SaveResultByTime("200103201400");
    CQueueSch::GetQueueSch()->SaveResultByTime("200103220325");
    CQueueSch::GetQueueSch()->SaveResultByTime("200103260144");
    CQueueSch::GetQueueSch()->SaveResultByTime("200103301001");
    CQueueSch::GetQueueSch()->SaveResultByTime("200104061014");
    CQueueSch::GetQueueSch()->SaveResultByTime("200104101119");
    CQueueSch::GetQueueSch()->SaveResultByTime("200104170844");
    CQueueSch::GetQueueSch()->SaveResultByTime("200104191008");
    CQueueSch::GetQueueSch()->SaveResultByTime("200105041454");
    CQueueSch::GetQueueSch()->SaveResultByTime("200107061100");
    CQueueSch::GetQueueSch()->SaveResultByTime("200107180906");
    CQueueSch::GetQueueSch()->SaveResultByTime("200109110914");
    CQueueSch::GetQueueSch()->SaveResultByTime("200110010633");
    CQueueSch::GetQueueSch()->SaveResultByTime("200110021034");
    CQueueSch::GetQueueSch()->SaveResultByTime("200110120811");
    CQueueSch::GetQueueSch()->SaveResultByTime("200111010504");
    CQueueSch::GetQueueSch()->SaveResultByTime("200111042000");
    CQueueSch::GetQueueSch()->SaveResultByTime("200111070056");
    CQueueSch::GetQueueSch()->SaveResultByTime("200111081017");
    CQueueSch::GetQueueSch()->SaveResultByTime("200112051140");
    CQueueSch::GetQueueSch()->SaveResultByTime("200112260905");
    */
    //CQueueSch::GetQueueSch()->SaveResultByTime("200102020800");
    //CQueueSch::GetQueueSch()->SaveResultByTime("200102051208");
    //CQueueSch::GetQueueSch()->SaveResultByTime("200102051249");
    //CQueueSch::GetQueueSch()->SaveResultByTime("200102051250");
    //CQueueSch::GetQueueSch()->SaveResultByTime("201506031600");

    return uiOrderNum;
}
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
// �ӿں궨��
/////////////////////////////////////////////////////////////
#define GETORDER_OUT_TRANSTYPE 0
#define GETORDER_OUT_OPENLOTS 1
#define GETORDER_OUT_STOPLOSS 2
#define GETORDER_OUT_TAKEPROFIT 3
#define GETORDER_OUT_STOPLOSSSTEP 4
#define GETORDER_OUT_MODIFYNUM 5
#define GETORDER_OUT_TICKET    6
/////////////////////////////////////////////////////////////
//+------------------------------------------------------------------+
//| �������ײ���                                                     |
//+------------------------------------------------------------------+
//����µ�:MQL���ô˺������ض�����Ϣ, ��������Ϣд������Ԫ�� -- ��TOrderNode�ṹ��Ӧ��
MT4_EXPFUNC UINT _stdcall QsGetOrderInfo(double *order,const int arraysize, int uiOrderIdx)
{
    EQ_RETURN_VALUE(order, NULL,QS_ERROR_2);
    LESS_RETURN_VALUE(arraysize, 5, QS_ERROR_3);
    GREATER_EQ_RETURN_VALUE(uiOrderIdx, MAX_TRANSECTION_NUM, QS_ERROR_4);
//QsGetOrderInfo 0.00000000 2.00000000 0.05934789 9.00000000 30.00000000 10.00000000
    order[GETORDER_OUT_TRANSTYPE] = CQueueSch::GetQueueSch()->GetOrderTransType(uiOrderIdx);
    order[GETORDER_OUT_OPENLOTS] = CQueueSch::GetQueueSch()->GetOrderOpenLots(uiOrderIdx);
    order[GETORDER_OUT_STOPLOSS] = CQueueSch::GetQueueSch()->GetOrderLossStop(uiOrderIdx);
    order[GETORDER_OUT_TAKEPROFIT] = CQueueSch::GetQueueSch()->GetOrderTakeProfit(uiOrderIdx);
    order[GETORDER_OUT_STOPLOSSSTEP] = CQueueSch::GetQueueSch()->GetStopLossStep(uiOrderIdx);
    order[GETORDER_OUT_MODIFYNUM] = CQueueSch::GetQueueSch()->GetOrderModifyNum(uiOrderIdx);
    if (order[GETORDER_OUT_TRANSTYPE] > TRANSECTION_SELL)//�ڷ����µ�����²� ��QS����ticket���µ���MT4��������ticket��
    {
        order[GETORDER_OUT_TICKET] = CQueueSch::GetQueueSch()->GetOrderTicket(uiOrderIdx);
    }

    return QS_SUCC;
}
/////////////////////////////////////////////////////////////
// �ӿں궨��
/////////////////////////////////////////////////////////////
#define SETORDER_IN_TRANSTYPE  0
#define SETORDER_IN_TICKET     6
#define SETORDER_IN_PRICE      7
/////////////////////////////////////////////////////////////
//MQL����������ϣ����Ͷ��������DLL, �ҵ��� �������С������������ʧ�ܣ����˵�free������һ���ж��Ƿ��µ���
//QsSetOrderResult 1.00000000 0.02971909 287.00000000 30.00000000 10.00000000        0.00000000 2.00000000 1.57520000
//QsSetOrderResult 1.00000000 0.01982494 287.00000000 30.00000000 10.00000000 0.00000000 3.00000000 1.57530000
MT4_EXPFUNC UINT _stdcall QsSetOrderResult(double *arr,const int arraysize,int uiOrderIdx)
{
    UINT uiOrderNum = 0;

    EQ_RETURN_VALUE(arr, NULL,QS_ERROR_5);
    LESS_RETURN_VALUE(arraysize, 1, QS_ERROR_6);
    GREATER_EQ_RETURN_VALUE(uiOrderIdx, MAX_TRANSECTION_NUM, QS_ERROR_7);

    if ((arr[SETORDER_IN_TRANSTYPE] > TRANSECTION_SELL_MOVESTEPLOSS)//��Χ����
        ||(arr[SETORDER_IN_TRANSTYPE] == TRANSECTION_WAIT)       //�������Ͳ���
        ||(arr[SETORDER_IN_TRANSTYPE] == TRANSECTION_CLOSE_BUY)  // ƽ buy
        ||(arr[SETORDER_IN_TRANSTYPE] == TRANSECTION_CLOSE_SELL) // ƽ sell
        ||(arr[SETORDER_IN_TRANSTYPE] == TRANSECTION_CLOSE_ALL)
        ||(arr[SETORDER_IN_TICKET] < 0))                          // ���ܱ����µ�����ʧ�ܣ�����-1����Ҫ�ͷţ��´����ж��Ƿ񿪵��� 
    {//������ʱ���ж�Ϊƽ��ʱ�� -- ��ƽ���ͷŶ���,4��5��;�ͷ���������� ����0
        CQueueSch::GetQueueSch()->RetOrder(uiOrderIdx, TRANSECTION_WAIT);
    }
    else
    {
        //arr��ͳһ�ӿڣ�0-5��MQL��Σ�6�����ǳ��Σ�ticket��price����
        CQueueSch::GetQueueSch()->SetOrder(uiOrderIdx, arr[SETORDER_IN_TICKET], arr[SETORDER_IN_PRICE]);
        //����MT4������ʼ���ⲿ֪ͨ������ֻ���������������������Ϊ���¶������޸�ֹ�𡢻��ǲ��֡����ֵ� ,//������waitlink�뵽buyselllink��ͬʱ�뵽��ʱ������
        CQueueSch::GetQueueSch()->StartOrder((USHORT)uiOrderIdx, (UINT)((UINT)arr[SETORDER_IN_TRANSTYPE]%3 + TRANSECTION_START_BUY - TRANSECTION_BUY));
        //ͳ�Ʊ���
        if ((arr[SETORDER_IN_TRANSTYPE] == TRANSECTION_BUY)||(arr[SETORDER_IN_TRANSTYPE] == TRANSECTION_SELL)
            ||(arr[SETORDER_IN_TRANSTYPE] == TRANSECTION_START_BUY)||(arr[SETORDER_IN_TRANSTYPE] == TRANSECTION_START_SELL))
        {
//#ifdef DBG_OUTPUT
            //�µ�ʱ��ӡ����QS��������txt
            CQueueSch::GetQueueSch()->SaveStatInfo(uiOrderIdx,(UINT)arr[SETORDER_IN_TICKET]);
//#endif
        }
    }
    
    //���ص�ǰ������������MT4�˶�
    uiOrderNum = CQueueSch::GetQueueSch()->GetOrderTotalNum();
#ifdef DBG_OUTPUT    
    //���Ա���
    extern UINT DebugOut;
    DebugOut = (UINT)arr[SETORDER_IN_TRANSTYPE];
    CQueueSch::GetQueueSch()->SaveDebugInfo(1,(UINT)arr[SETORDER_IN_TICKET]);
#endif
    return uiOrderNum;
}
/////////////////////////////////////////////////////////////
// �ӿں궨��
/////////////////////////////////////////////////////////////
#define SYNCORDER_IN_NUM        0
#define SYNCORDER_IN_TICKET     1
#define SYNCORDER_IN_TRANSTYPE  2
#define SYNCORDER_IN_OPENLOTS   3
#define SYNCORDER_IN_STOPLOSS   4
#define SYNCORDER_IN_TAKEPROFIT 5
#define SYNCORDER_IN_PRICE      6
/////////////////////////////////////////////////////////////
//�����ֶ��������¶�����Ϣ��ƥ��ʱ��ͬ����Ϣ
MT4_EXPFUNC UINT _stdcall QsSyncOrder(double *arr,const int arraysize)
{
    UINT uiOrderNum = 0;
    UINT uiSyncNum  = 0;
    TOrderNode tOrder;

    EQ_RETURN_VALUE(arr, NULL,QS_ERROR_5);
    LESS_RETURN_VALUE(arraysize, 6, QS_ERROR_6);
    //LESS_RETURN_VALUE(uiOrderNum, 1, QS_ERROR_22);//bug

    uiOrderNum = (UINT)arr[SYNCORDER_IN_NUM];
    LESS_RETURN_VALUE(uiOrderNum, 1, QS_ERROR_22);

    memset(&tOrder, 0, sizeof(TOrderNode));

    //�ж�order����
    for(UINT i = 0; i < uiOrderNum; i++)
    {
        tOrder.dTicket            =  arr[SYNCORDER_IN_TICKET   +6*i ];
        tOrder.uiTransectionType   = (UINT)arr[SYNCORDER_IN_TRANSTYPE+6*i ];
        tOrder.dOpenLots           = arr[SYNCORDER_IN_OPENLOTS  +6*i];
        tOrder.dLossStop           = arr[SYNCORDER_IN_STOPLOSS  +6*i];
        tOrder.dTakeProfit         = arr[SYNCORDER_IN_TAKEPROFIT+6*i];
        tOrder.dPrice              = arr[SYNCORDER_IN_PRICE     +6*i];

        uiSyncNum += CQueueSch::GetQueueSch()->SyncOrder(&tOrder);
    }

    return uiSyncNum;
}

/////////////////////////////////////////////////////////////
//��ʱ����
/////////////////////////////////////////////////////////////
/*
#if 0
{
MT4_EXPFUNC double _stdcall GetOpenValue(RateInfo *Rates, int MaximumRecords, int Iteration)
{
    return (Rates[MaximumRecords - Iteration - 1].open);
}

MT4_EXPFUNC double _stdcall GetCloseValue(RateInfo *Rates, int MaximumRecords, int Iteration)
{
    return (Rates[MaximumRecords - Iteration - 1].close);
}

MT4_EXPFUNC UINT _stdcall QsStrCmp(const void *left,const void *right)
{
    return CQueueSch::GetQueueSch()->MqlStrCmp(left, right);
}

//�������������ݣ�����DLL��MQL����
MT4_EXPFUNC BOOL __stdcall QsSetArrayItemValue(double *arr,const int arraysize,const int idx,const double value)
  {
//---
   if(arr==NULL)
     {
      printf("QsSetArrayItemValue: NULL array\n");
      return(FALSE);
     }
   if(arraysize<=0)
     {
      printf("QsSetArrayItemValue: wrong arraysize (%d)\n", arraysize);
      return(FALSE);
     }
   if(idx<0 || idx>=arraysize)
     {
      printf("QsSetArrayItemValue: wrong item number (%d)\n", idx);
      return(FALSE);
     }
//---
   arr[idx]=value;
   return(TRUE);
  }
}
MT4_EXPFUNC BOOL __stdcall SetArrayItemValue(double *arr,const int arraysize,const int nitem,const double value)
  {
//---
   if(arr==NULL)
     {
      printf("GetArrayItemValue: NULL array\n");
      return(FALSE);
     }
   if(arraysize<=0)
     {
      printf("GetArrayItemValue: wrong arraysize (%d)\n", arraysize);
      return(FALSE);
     }
   if(nitem<0 || nitem>=arraysize)
     {
      printf("GetArrayItemValue: wrong item number (%d)\n", nitem);
      return(FALSE);
     }
//---
   arr[nitem]=value;
   return(TRUE);
  }
MT4_EXPFUNC double __stdcall GetRatesItemValue(const RateInfo* rates,const int rates_total,const int shift,const int nrate)
  {
//---
   if(rates==NULL)
     {
      printf("GetRatesItemValue: NULL array\n");
      return(0.0);
     }
//---
   if(rates_total<0)
     {
      printf("GetRatesItemValue: wrong rates_total number (%d)\n", rates_total);
      return(0.0);
     }
//---
   if(shift<0 || shift>=rates_total)
     {
      printf("GetRatesItemValue: wrong shift number (%d)\n", shift);
      return(0.0);
     }
//---
   if(nrate<0 || nrate>5)
     {
      printf("GetRatesItemValue: wrong rate index (%d)\n", nrate);
      return(0.0);
     }
//---
   int nitem=rates_total-1-shift;
   switch(nrate)
     {
      case 0: return double(rates[nitem].ctm);
      case 1: return rates[nitem].open;
      case 2: return rates[nitem].low;
      case 3: return rates[nitem].high;
      case 4: return rates[nitem].close;
      case 5: return rates[nitem].vol;
     }
//---
   return(0.0);
  }
#endif
  */


