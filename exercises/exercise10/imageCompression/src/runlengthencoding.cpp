#include "runlengthencoding.h"
#include <algorithm>
#include <iterator>


namespace RunLengthEncoding
{
    void encode(const TGAImage& inputImage, std::ostream& os)
    {
        TGAImageHeader header = inputImage.getHeader();  //to get Output of privatmember header in TGAImage
        header.setCompressed();
        os << header;
        // TODO: Implement here
        //inputImage.getData();   get std::vector<ARGB32> data;
        std::vector<ARGB32>::const_iterator iter;
        for(iter=inputImage.getData().begin();iter!=inputImage.getData().end();++iter)
        { 
            os<<*iter; 
        }
        auto i1=std::adjacent_find(inputImage.getData().begin(),inputImage.getData().end());
        if(i1==inputImage.getData().end())
        {
           os<<"no matching adjacent elements\n";
        }
        else
        {
           os<< "the first adjacent pair of equal elements at: "<< std::distance(inputImage.getData().begin(), i1) <<std::endl;
        }
        auto prev=[](ARGB32 a,ARGB32 b)
        {
           if(a==b)
          {  
            ARGB32* p1=&a; ARGB32* p2=&b;
            return *p1==*p2 && *p2!=*(p2+1);
          }  
           else
          {return false; }
        };
        std::find_if(inputImage.getData().begin(),inputImage.getData().end(),prev);
    }

    TGAImage decode(std::istream& is)
    {
        TGAImage image;
        is >> image.getHeader();
        image.getHeader().setUncompressed();

        // TODO: Implement here

        return image;
    }

    void encode(const std::string& inputFilename, const std::string& outputFilename)
    {
        std::ifstream is(inputFilename, std::ios::in | std::ios::binary);
        TGAImage inputImage;
        is >> inputImage;
        is.close();
        encode(inputImage, outputFilename);
    }

    void encode(const TGAImage& inputImage, const std::string& outputFilename)
    {
        std::ofstream os(outputFilename, std::ios::out | std::ios::binary);
        encode(inputImage, os);
        os.close();
    }

    void decode(const std::string& inputFilename, const std::string& outputFilename)
    {
        std::ofstream os(outputFilename, std::ios::out | std::ios::binary);
        TGAImage inputImage = decode(inputFilename);
        os << inputImage;
        os.close();
    }

    TGAImage decode(const std::string& inputFilename)
    {
        std::ifstream is(inputFilename, std::ios::in | std::ios::binary);
        TGAImage inputImage = decode(is);
        is.close();
        return inputImage;
    }
}

