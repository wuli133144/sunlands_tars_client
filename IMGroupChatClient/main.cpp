#include <iostream>
#include <sstream>
#include "servant/Communicator.h"
#include "IMGroupChatObj.h"
 




using namespace std;

using namespace IMGroupChatApp ;

using namespace tars;

string int2string(uint32_t user_id)
{
    stringstream ss;
    ss << user_id;
    return ss.str();
}

uint32_t string2int(const string& value)
{
    return (uint32_t)atoi(value.c_str());
}



 

int main(int argc,char ** argv)

{

    Communicator comm;

 

    try

    {

        IMGroupChatObjPrx prx;

        comm.stringToProxy("IMGroupChatApp.IMGroupChatServer.IMGroupChatObjObj@tcp -h 172.16.103.125 -p 20005" , prx);

 

        try

        {  
         while(1){
          IMGroupModifyTopReq info;
          IMGroupModifyTopResp inforesp;

          info.user_id=15;
          info.group_id=2;
          string user_id_str,group_id_str, ontop;
          std::cout<<"用户id:"<<std::endl;
          std::cin>>user_id_str;
          info.user_id=string2int(user_id_str);
          
          std::cout<<"组id:"<<std::endl;
          std::cin>>group_id_str;
          info.group_id=string2int(group_id_str);
          
          std::cout<<"是否置顶[1:yes,2:no]:"<<std::endl;
          std::cin>>ontop;
          info.ontop=string2int(ontop);
          
         
          prx->setontop(info,inforesp);
          cout<<"user_id="<<info.user_id<<"group_id="<<info.group_id<<endl;
        

        }
   }
        catch(exception &ex)

        {

            cerr << "ex:" << ex.what() << endl;

        }

        catch(...)

        {

            cerr << "unknown exception." << endl;

        }

    }

    catch(exception& e)

    {

        cerr << "exception:" << e.what() << endl;

    }

    catch (...)

    {

        cerr << "unknown exception." << endl;

    }

 

    return 0;

}

 
